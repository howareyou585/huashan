#pragma once
#include <map>
#include <vector>
#include <functional>
using namespace std;
template<typename ... args>
class Event
{
public:
	Event() = default;
	~Event()
	{
		disconnect();
	}
	Event(const Event&) = delete;
	Event& operator = (const Event&) = delete;
	//Connects a std::function to the signal.
	void connect(const function<void(args...)> &slot)
	{
		static unsigned long id = 0;
		m_mapSlot[id] = slot;
		id++;
	}
	// Convenience method to connect a const member function
	// of an object to this Event.
	template<typename T>
	void connect_member(const T* ptrInst, void(T::* memeberFuncPtr)(args...))
	{
		if (!ptrInst)
		{
			return;
		}

		connect([=](args... paramters) {
			(ptrInst->*memeberFuncPtr)(paramters...);
			});
	}
	void disconnect(const unsigned long id)
	{
		auto it = m_mapSlot.find(id);
		if (it != m_mapSlot.end())
		{
			m_mapSlot.erase(it);
		}
	}
	void disconnect(vector<unsigned long> &vecId)
	{
		for (auto it = vecId.begin(); it!=vecId.end(); it++)
		{
			auto id = *it;
			disconnect(id);
		}
	}
	void disconnect()
	{
		map<unsigned long, function<void(args...)>>().swap(m_mapSlot);
	}
	void emit(args... paramters)
	{
		for (auto it = m_mapSlot.begin(); it != m_mapSlot.end(); it++)
		{
			it->second(paramters ...);
		}
	}
private:
	map<unsigned long, function<void(args...)>> m_mapSlot;
};