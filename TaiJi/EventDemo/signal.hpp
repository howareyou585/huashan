#pragma once
#include "Slot.hpp"
#include <list>
using namespace std;
namespace Event
{
	template<typename ...TParam>
	class Signal
	{
	public:
		Signal& operator+= (SlotBase<TParam...>*ptrSlot)
		{
			if (ptrSlot)
			{
				m_lstSlot.emplace_back(ptrSlot);
			}
			return *this;
		}
		Signal& operator-=(SlotBase<TParam...>*ptrSlot)
		{
			if (ptrSlot)
			{
				auto it = ::find(m_lstSlot.begin(), m_lstSlot.end(), ptrSlot);
				if (m_lstSlot.end() != it)
				{
					m_lstSlot.erase(it);
				}
			}
			return *this;
		}
		void operator()(TParam... parameters)
		{
			for (auto it = m_lstSlot.begin(); it != m_lstSlot.end(); it++)
			{
				auto ptrSlot = *it;
				if (!ptrSlot)
				{
					continue;
				}
				
				ptrSlot(parameters...);
				
			}
		}
	private:
		list<SlotBase<TParam...>*>m_lstSlot;
	};
}

