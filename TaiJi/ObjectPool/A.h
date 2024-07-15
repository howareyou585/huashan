#pragma once
#include "ObjectPool.hpp"
#include "MallocAllocator.h"
#include "ArrayAllocator.hpp" // 数组策略
#include "HeapAlloctor.h"	  // 堆策略
#include "StackAlloctor.hpp"  // 栈策略
namespace TaiJi
{
	const int max_size = 10;
	class A
	{
	public:
		A();
		~A();
		void SetState(int state);
		int GetState();
	public:
		static void * operator new(size_t size);
		static void  operator delete(void *p);
	private:
		int m_state;
		//static void  operator delete(void * ptrHeader);
	private:
		//static ObjectPool<A, ArrayAllocator<A, max_size>> m_pool;
		//static ObjectPool<A, HeapAlloctor<A, max_size>> m_pool;
		static ObjectPool<A, StackAllocator<A, max_size>> m_pool;

	};

}