#pragma once
#include "MallocAllocator.h"
#include "ObjectPool.hpp"
#include "A.h"
namespace TaiJi
{
	void testMallocAllocator()
	{
		MallocAllocator<A> myAlloctor;
		ObjectPool<A, MallocAllocator<A>> pool;
	}
}