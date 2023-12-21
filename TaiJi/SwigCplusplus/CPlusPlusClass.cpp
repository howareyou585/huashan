
#include "CPlusPlusClass.h"
#include <iostream>

using namespace std;


SimpleCallback::SimpleCallback()
{
	std::cout << "invoke SimpleCallback::SimpleCallback()" << endl;
}

SimpleCallback::~SimpleCallback()
{
	std::cout << "SimpleCallback::~SimpleCallback()" << endl;
}

void SimpleCallback::run()
{
	std::cout << "SimpleCallback::run()" << endl;
}

Caller::Caller():m_ptrCallback(0)
{

}

Caller::~Caller()
{

}

void Caller::setCallback(SimpleCallback* ptrCallback)
{
	m_ptrCallback = ptrCallback;
}

void Caller::resetCallback()
{
	m_ptrCallback = nullptr;
}

SimpleCallback* Caller::getCallBack()
{
	return m_ptrCallback;
}

void Caller::call()
{
	if (m_ptrCallback)
	{
		m_ptrCallback->run();
	}
}
