#pragma once
#include "Allocator.hpp"
namespace TaiJi
{
	template<typename T,typename Alloc>
	class ObjectPool
	{
	public:
		ObjectPool() = default;
		virtual ~ObjectPool() = default;
		T* allocate(size_t size)
		{
			return m_allocator.allocate();
		}
		void deallocate(T* p)
		{
			m_allocator.deallocate(p);
		}
		/*void setAllocator(Alloc& allocator)
		{
			m_allocator = allocator;
		}*/
	private:
		Alloc m_allocator;
	};
}