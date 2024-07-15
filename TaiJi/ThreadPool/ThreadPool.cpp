#include "ThreadPool.h"

namespace ThreadPool
{
	ThreadPool::ThreadPool(unsigned int num) :m_stop(false)
	{
		if (num <= 1)
		{
			m_threadNum = 2;
		}
		else
		{
			m_threadNum = num;
		}
		start();
	}

	void ThreadPool::start()
	{
		for (int i = 0; i < m_threadNum; i++)
		{
			//向线程池中添加工作线程
			m_pool.emplace_back([this]() {
				
				while (!this->m_stop.load())//检查是否要退出线程池
				{
					Task task;
					{
						unique_lock<mutex> ulock(this->m_mutex);
						this->m_cv.wait(ulock, [this] {
							//当要结束线程池或任务队列中的任务为空时，
							return this->m_stop.load() || !this->m_queTask.empty();
						});
						if (this->m_queTask.empty())
						{
							return;
						}
						task = std::move(this->m_queTask.front()); // 任务出队
						this->m_queTask.pop();
					}
					this->m_threadNum--;//在线程中执行Task，可用线程数量-1;
					task();
					//线程中执行Task后，可用线程数量+1;
				}
				});
		}
	}

	void ThreadPool::stop()
	{
		//将停止状态设置为ture
		m_stop.store(true);
		unique_lock<mutex> ulock(m_mutex);
		//唤醒所有挂起的线程
		m_cv.notify_all();
		for (auto & td: m_pool)
		{
			if (td.joinable())
			{
				td.join();
			}
		}
	}

	ThreadPool::~ThreadPool()
	{
		stop();
	}
	int ThreadPool::idleThreadNum()
	{
		return m_threadNum;
	}
	//单例模式
	ThreadPool& ThreadPool::Instance()
	{
		static ThreadPool ins;
		return ins;
	}
}