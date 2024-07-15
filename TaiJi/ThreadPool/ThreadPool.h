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
		using Task = packaged_task<void()>; //�ɵ��ö���
	public:
		
		~ThreadPool();
		int idleThreadNum();
		//�������������������
		template<typename F, typename ...Args> 
		auto commit(F&& f, Args&&... args)->
			std::future<decltype(forward<F>(f)(forward<Args>(args)...))>
		{
			
			using RetType = decltype(forward<F>(f)(forward<Args>(args)...));
			if (m_stop.load())
			{
				return std::future<RetType>{};//???��д����{}�ĳ�ʼ��������???
			}
			//��������õ����������
			auto ptrTask = make_shared<packaged_task<RetType()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
			future<RetType> retFuture = ptrTask->get_future();
			unique_lock<mutex>ulock(m_mutex);
			
			m_queTask.emplace([ptrTask]() 
				{(*ptrTask)(); }); // �����ߣ�׼�������ݣ���һ��Ҫ֪ͨ�����̣߳������Ѿ�׼�����ˣ��������ˡ�
			m_cv.notify_one();

			return retFuture;
		}

		
	public:
		static ThreadPool& Instance();
	private:
		ThreadPool(unsigned int num = std::thread::hardware_concurrency());//����ģʽ�����캯��˽�С������û����ⲿ����
	private:
		void start();
		void stop();
	private:
		vector<thread>m_pool;		//�̶߳���
		queue<Task> m_queTask;		//�������:�Ƚ��ȳ�
		std::atomic_int m_threadNum;//�̵߳�����
		std::atomic_bool m_stop;		//�̳߳��Ƿ��˳�
		mutex m_mutex;					//
		condition_variable m_cv;
	};
	
}

