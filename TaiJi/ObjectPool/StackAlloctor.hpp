//堆栈策略内存分配器
#pragma once
#include <array>
#include "Allocator.hpp"
using namespace std;
namespace TaiJi
{
	template<typename T, int N>
	class StackAllocator :public Allocator<T>
	{
	public:
		StackAllocator()
		{
			m_allocated = 0;
			m_avilable = 0;
		}
		virtual ~StackAllocator() = default;
	public:
		virtual T * allocate()
		{
			T* ptrObject = nullptr;
			if (m_avilable <= 0 && m_allocated >= N)
			{
				throw std::bad_alloc();
			}
			if (m_avilable > 0)
			{
				//堆栈中有可用的对象
				ptrObject = m_stack[m_avilable--];//栈顶的元素出栈了
			}
			else
			{
				//堆栈中没有可用对象：要从原始的数组分配
				ptrObject = reinterpret_cast<T*>(m_data + sizeof(T) * m_allocated);
				++m_allocated;//用来指向下一个可用对象
			}
			return ptrObject;

		}
		virtual void deallocate(T* p) {
			if (!p)
			{
				return;
			}
			//回收 p对象 对应的空间到栈中
			m_stack[m_avilable++] = p;

		}
	private:
		char m_data[sizeof(T)*N];//连续的内存空间
		array<T*, N> m_stack;// 存放可用的内存
		int m_allocated;//记录数组m_data下一个未使用对象的位置。
		int m_avilable;//记录m_stack中要出栈元素的位置。
	};
}