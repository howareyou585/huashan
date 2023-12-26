#include "ThreadFunc.h"
#include <iostream>
#include <thread>

using namespace std;
void print(int num)
{
	this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "thread id =" << num << std::endl;
}
void diveZero()
{
	int a = 100;
	int b = 0;
	int c = a / 0;
	cout << c << endl;
}

void MsgQueque::inputMsg()
{
	for (int i = 0; i < 10000; i++)
	{
		/*m_mutex.lock();
		m_mutex2.lock();*/
		std::lock(m_mutex_a, m_mutex_b);
		{
			std::lock_guard<mutex> lg(m_mutex_a, adopt_lock);
			std::lock_guard<mutex> lg2(m_mutex_b, adopt_lock);
			queNumber.emplace_back(i);
		}
		/*m_mutex2.unlock();
		m_mutex.unlock();*/
		cout << "入队操作:" << i << endl;
	}
}

void MsgQueque::outputMsg()
{
	while (true)
	{
		std::lock(m_mutex_a, m_mutex_b);
		{
			std::lock_guard<mutex> lg(m_mutex_a, adopt_lock);
			std::lock_guard<mutex> lg2(m_mutex_b, adopt_lock);
			if (!queNumber.empty())
			{
				auto val = queNumber.front();
				queNumber.pop_front();
				cout << "出队操作:" << val << endl;
			}
		}
		/*m_mutex2.unlock();
		m_mutex.unlock();*/
		
	}
}

void MsgQueque::deadlockInputMsg()
{
	for (int i = 0; i < 10000; i++)
	{
		{
			std::lock_guard<mutex> lock_a(m_mutex_a); // 先加a锁
			std::lock_guard<mutex> lock_b(m_mutex_b); // 后加b锁
			queNumber.emplace_back(i);
		}
		cout << "入队操作:" << i << endl;
	}
}

void MsgQueque::deadlockOutputMsg()
{
	while (true)
	{
		std::lock_guard<mutex> lock_b(m_mutex_b);//先加b锁
		std::lock_guard<mutex> lock_a(m_mutex_a);//后加a锁
		if (!queNumber.empty())
		{
			auto val = queNumber.front();
			queNumber.pop_front();
			cout << "出队操作:" << val << endl;
		}
	}
}

void MsgQueque::uniqueLockInputMsg()
{
	for (int i = 0; i < 10000; i++)
	{
		cout << "uniqueLockInputMsg()执行，插入一个元素" << i << endl;
		unique_lock<mutex> ulock(m_mutex_a, std::try_to_lock); //当拿不到锁时，让程序不会阻塞在这里，
		if (ulock.owns_lock())
		{
			//拿到了锁
			queNumber.emplace_back(i);
			//todo
		}
		else
		{
			//没拿到锁
			cout << "inMsgRecvQueue()执行，但没拿到锁头，只能干点别的事" << i << endl;
		}
		
	}
}

void MsgQueque::uniqueLockOutputMsg()
{
	int command = 0;
	for (int i = 0; i < 10000; i++)
	{
		if (outMsgLULProc(command))
		{
			cout << "uniqueLockOutputMsg()执行，取出一个元素" << endl;
		}
		else
		{
			cout << "uniqueLockOutputMsg()执行，但目前消息队列中为空！" << i << endl;
		}
	}
}

bool MsgQueque::outMsgLULProc(int& command)
{
	//m_mutex_a.lock();  
	//lock_guard<mutex> lg(m_mutex_a, std::adopt_lock); //std::adopt_lock 前提是在调用前一定要让互斥量lock
	unique_lock<mutex> ulock(m_mutex_a);  
	std::chrono::milliseconds duar(2000);
	std::this_thread::sleep_for(duar);
	if (!queNumber.empty())
	{
		command = queNumber.front();
		queNumber.pop_front();
		return true;
	}
	return false;
}
