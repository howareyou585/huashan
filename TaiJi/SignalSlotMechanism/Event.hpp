#pragma once
#include <map>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;
template<typename ... args>
class Event
{
public:
	//默认构造函数
	Event() = default;
	//默认析构函数
	~Event()
	{
		disconnect();
	}
	Event(const Event&) = delete;
	Event& operator = (const Event&) = delete;
	//Connects a std::function to the signal.
	int connect(const function<void(args...)> &slot)
	{
		int signalId = -1;
		static unsigned long id = 0;
		m_mapSlot[id] = slot;
		signalId = id;
		id++;
		return signalId;
	}
	// Convenience method to connect a const member function
	// of an object to this Event.
	template<typename T>
	int connect_member( T* ptrInst, void(T::* memeberFuncPtr)(args...))
	{
		int siginalId = -1;
		if (!ptrInst)
		{
			return siginalId;
		}
		
		siginalId = connect([=](args... paramters) {
			(ptrInst->*memeberFuncPtr)(paramters...);
			});
		return siginalId;
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
			cout << "signal id = " << it->first << endl;
			it->second(paramters ...);
		}
	}
	// Calls all connected functions except for one.
	void emit_for_all_but_some(args... paramters, const vector<unsigned long>& vecId)
	{
		for (auto it = m_mapSlot.begin(); it != m_mapSlot.end(); it++)
		{
			auto signalId = it->first;
			if (vecId.end() == ::find(vecId.begin(), vecId.end(), signalId))
			{
				it->second(paramters ...);
			}
		}
	}

	void emit_for(args... paramters, const vector<unsigned long>& vecId)
	{
		map<unsigned long, function<void(args...)>> mapSlot;
		for (auto it = vecId.begin(); it != vecId.end(); it++)
		{
			auto id = *it;
			if (m_mapSlot.end() != m_mapSlot.find(id))
			{
				mapSlot[id] = m_mapSlot[id];
			}
		}
		for (auto it = mapSlot.begin(); it != mapSlot.end(); it++)
		{
			it->second(paramters ...);
		}
	}
private:
	map<unsigned long, function<void(args...)>> m_mapSlot;
};