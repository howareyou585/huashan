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
		cout << "��Ӳ���:" << i << endl;
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
				cout << "���Ӳ���:" << val << endl;
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
			std::lock_guard<mutex> lock_a(m_mutex_a); // �ȼ�a��
			std::lock_guard<mutex> lock_b(m_mutex_b); // ���b��
			queNumber.emplace_back(i);
		}
		cout << "��Ӳ���:" << i << endl;
	}
}

void MsgQueque::deadlockOutputMsg()
{
	while (true)
	{
		std::lock_guard<mutex> lock_b(m_mutex_b);//�ȼ�b��
		std::lock_guard<mutex> lock_a(m_mutex_a);//���a��
		if (!queNumber.empty())
		{
			auto val = queNumber.front();
			queNumber.pop_front();
			cout << "���Ӳ���:" << val << endl;
		}
	}
}

void MsgQueque::uniqueLockInputMsg()
{
	for (int i = 0; i < 10000; i++)
	{
		cout << "uniqueLockInputMsg()ִ�У�����һ��Ԫ��" << i << endl;
		unique_lock<mutex> ulock(m_mutex_a, std::try_to_lock); //���ò�����ʱ���ó��򲻻����������
		if (ulock.owns_lock())
		{
			//�õ�����
			queNumber.emplace_back(i);
			//todo
		}
		else
		{
			//û�õ���
			cout << "inMsgRecvQueue()ִ�У���û�õ���ͷ��ֻ�ܸɵ�����" << i << endl;
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
			cout << "uniqueLockOutputMsg()ִ�У�ȡ��һ��Ԫ��" << endl;
		}
		else
		{
			cout << "uniqueLockOutputMsg()ִ�У���Ŀǰ��Ϣ������Ϊ�գ�" << i << endl;
		}
	}
}

bool MsgQueque::outMsgLULProc(int& command)
{
	//m_mutex_a.lock();  
	//lock_guard<mutex> lg(m_mutex_a, std::adopt_lock); //std::adopt_lock ǰ�����ڵ���ǰһ��Ҫ�û�����lock
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
