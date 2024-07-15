#include "A.h"
#include <iostream>
using namespace std;
namespace TaiJi
{
	//ObjectPool<A, ArrayAllocator<A, 10>> A::m_pool;
	//ObjectPool<A, HeapAlloctor<A, 10>> A::m_pool;
	ObjectPool<A, StackAllocator<A, max_size>>A::m_pool;
	A::A()
	{
		cout << "A::A()" << endl;
	}


	A::~A()
	{
		cout << "A::~A()" << endl;
	}

	void A::SetState(int state)
	{
		m_state = state;
	}

	int A::GetState()
	{
		return m_state;
	}

	void * A::operator new(size_t size)
	{
		cout << "A new from object pool." << endl;
		//void * ptrRet = malloc(size);
		void *ptrRet = m_pool.allocate(size);
		return ptrRet;
	}
	//void A::operator delete(void * ptrHeader)
	void A::operator delete(void * p)
	{
		cout << "A delete from object pool." << endl;
		m_pool.deallocate(static_cast<A*>( p));
		//free(p);
		//p = nullptr;
	}
}