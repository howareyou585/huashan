#pragma once
#include "Allocator.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;
namespace TaiJi
{
	template<typename T, int N>
	class ArrayAllocator :public Allocator<T>
	{
	public:
		ArrayAllocator() = default;
		~ArrayAllocator() = default;
	public:
		virtual T * allocate()
		{
			cout << "invoke ArrayAllocator::allocate()" << endl;
			for (int i = 0; i < N; i++)
			{
				if (!m_aryUsed[i])
				{
					m_aryUsed[i] = true;
					return reinterpret_cast<T*>(m_aryData[i * sizeof(T)]);
				}
			}
			throw std::bad_alloc();
		}
		virtual void deallocate(T* p)
		{
			/*for (auto i = 0; i < N; i++)
			{
				if (p == m_aryData[i * sizeof(T)])
				{
					m_aryUsed[i] = false;
					break;
				}
			}*/
			cout << "invoke ArrayAllocator::deallocate()" << endl;
			int i = ((reinterpret_cast<char*>(p)) - m_aryData) / sizeof(T);
			m_aryUsed[i] = false;
		}
	private:
		char m_aryData[N * sizeof(T)];
		bool m_aryUsed[N];
	};
}