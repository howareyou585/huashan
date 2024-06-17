#pragma once
#include "ObjectPool.hpp"
#include "MallocAllocator.h"
#include "ArrayAllocator.hpp"
namespace TaiJi
{
	class A
	{
	public:
		A();
		~A();
		static void * operator new(size_t size);
		static void  operator delete(void *p);
	private:
		static ObjectPool<A, ArrayAllocator<A,10>> m_pool;
	};

}