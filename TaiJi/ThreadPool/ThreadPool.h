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

