#pragma once
#include "NoneCopy.h"
#include <thread>
#include <future>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <vector>
using namespace std;
namespace ThreadPool
{
	class ThreadPool:public NoneCopy
	{
		using Task = packaged_task<void()>; //可调用对象
	public:
		
		~ThreadPool();
		int idleThreadNum();
		//往任务队列中推送任务
		template<typename F, typename ...Args> 
		auto commit(F&& f, Args&&... args)->
			std::future<decltype(forward<F>(f)(forward<Args>(args)...))>
		{
			
			using RetType = decltype(forward<F>(f)(forward<Args>(args)...));
			if (m_stop.load())
			{
				return std::future<RetType>{};//???这写是用{}的初始化功能吗???
			}
			//将任务放置到任务队列中
			auto ptrTask = make_shared<packaged_task<RetType()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
			future<RetType> retFuture = ptrTask->get_future();
			unique_lock<mutex>ulock(m_mutex);
			
			m_queTask.emplace([ptrTask]() 
				{(*ptrTask)(); }); // 生产者，准备好数据，下一步要通知其他线程，数据已经准备好了，可以用了。
			m_cv.notify_one();

			return retFuture;
		}

		
	public:
		static ThreadPool& Instance();
	private:
		ThreadPool(unsigned int num = std::thread::hardware_concurrency());//单例模式：构造函数私有。不让用户在外部创建
	private:
		void start();
		void stop();
	private:
		vector<thread>m_pool;		//线程队列
		queue<Task> m_queTask;		//任务队列:先进先出
		std::atomic_int m_threadNum;//线程的数量
		std::atomic_bool m_stop;		//线程池是否退出
		mutex m_mutex;					//
		condition_variable m_cv;
	};
	
}

