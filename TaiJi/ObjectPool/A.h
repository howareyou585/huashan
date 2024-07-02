#pragma once
#include "ObjectPool.hpp"
#include "MallocAllocator.h"
#include "ArrayAllocator.hpp" // �������
#include "HeapAlloctor.h"	  // �Ѳ���
namespace TaiJi
{
	const int max_size = 10;
	class A
	{
	public:
		A();
		~A();
		static void * operator new(size_t size);
		static void  operator delete(void *p);
		//static void  operator delete(void * ptrHeader);
	private:
		//static ObjectPool<A, ArrayAllocator<A, max_size>> m_pool;
		static ObjectPool<A, HeapAlloctor<A, max_size>> m_pool;
	};

}