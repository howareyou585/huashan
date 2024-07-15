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
			//���̳߳�����ӹ����߳�
			m_pool.emplace_back([this]() {
				
				while (!this->m_stop.load())//����Ƿ�Ҫ�˳��̳߳�
				{
					Task task;
					{
						unique_lock<mutex> ulock(this->m_mutex);
						this->m_cv.wait(ulock, [this] {
							//��Ҫ�����̳߳ػ���������е�����Ϊ��ʱ��
							return this->m_stop.load() || !this->m_queTask.empty();
						});
						if (this->m_queTask.empty())
						{
							return;
						}
						task = std::move(this->m_queTask.front()); // �������
						this->m_queTask.pop();
					}
					this->m_threadNum--;//���߳���ִ��Task�������߳�����-1;
					task();
					//�߳���ִ��Task�󣬿����߳�����+1;
				}
				});
		}
	}

	void ThreadPool::stop()
	{
		//��ֹͣ״̬����Ϊture
		m_stop.store(true);
		unique_lock<mutex> ulock(m_mutex);
		//�������й�����߳�
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
	//����ģʽ
	ThreadPool& ThreadPool::Instance()
	{
		static ThreadPool ins;
		return ins;
	}
}