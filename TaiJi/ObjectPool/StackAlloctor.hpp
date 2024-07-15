//��ջ�����ڴ������
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
				//��ջ���п��õĶ���
				ptrObject = m_stack[m_avilable--];//ջ����Ԫ�س�ջ��
			}
			else
			{
				//��ջ��û�п��ö���Ҫ��ԭʼ���������
				ptrObject = reinterpret_cast<T*>(m_data + sizeof(T) * m_allocated);
				++m_allocated;//����ָ����һ�����ö���
			}
			return ptrObject;

		}
		virtual void deallocate(T* p) {
			if (!p)
			{
				return;
			}
			//���� p���� ��Ӧ�Ŀռ䵽ջ��
			m_stack[m_avilable++] = p;

		}
	private:
		char m_data[sizeof(T)*N];//�������ڴ�ռ�
		array<T*, N> m_stack;// ��ſ��õ��ڴ�
		int m_allocated;//��¼����m_data��һ��δʹ�ö����λ�á�
		int m_avilable;//��¼m_stack��Ҫ��ջԪ�ص�λ�á�
	};
}