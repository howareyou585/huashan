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

