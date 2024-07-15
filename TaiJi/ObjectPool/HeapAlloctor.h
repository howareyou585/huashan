#pragma once
#include "Allocator.hpp"
#include <algorithm>
using namespace std;
namespace TaiJi
{
	template<typename T, int N>
	class HeapAlloctor :
		public Allocator<T>
	{
		enum  State
		{
			FREE = 1,	// δʹ��
			USED = 0	// ��ʹ��
		};

		struct Entry
		{
			State state; //״̬
			T* p; //����ָ��
			bool operator < (const Entry& other) const
			{
				return state < other.state;
			}
		};
	public:
		HeapAlloctor()
		{
			m_avaliable = N;
			for (int i = 0; i < N; i++)
			{
				m_entry[i].state = State::FREE;
				m_entry[i].p = reinterpret_cast<T*>(m_data[i * sizeof(T)]);
			}
			//�������ɴ�ѵ��㷨
			std::make_heap(m_entry, m_entry + N);

		}
		virtual ~HeapAlloctor() = default;
		virtual T * allocate() override
		{
			if (m_avaliable <= 0)
				throw std::bad_alloc();
			Entry e = m_entry[0];
			std::pop_heap(m_entry, m_entry + N);
			m_avaliable--;
			m_entry[m_avaliable].state = State::USED;
			m_entry[m_avaliable].p = nullptr;
			return e.p;
		}
		virtual void deallocate(T* p) override
		{
			if (p == nullptr || m_avaliable >= N)
			{
				return;
			}
			m_entry[m_avaliable].state = State::FREE;
			m_entry[m_avaliable].p = reinterpret_cast<T*>(p);
			m_avaliable++;
			std::push_heap(m_entry, m_entry + N);
		}
	private:
		unsigned char m_data[N * sizeof(T)];
		Entry m_entry[N];
		int m_avaliable;//�Ƿ���ڿ��ö����ʶ
	};
}

