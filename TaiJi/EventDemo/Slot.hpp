#pragma once
namespace Event
{
	template<typename... TParam>
	class SlotBase
	{
	public:
		using FuncPointerType = void(*)(TParam...);
		SlotBase() {}
		SlotBase(FuncPointerType ptrFunc)
		{
			m_ptrFunc = ptrFunc;
		}
	private:
		FuncPointerType m_ptrFunc;
	};

	template<typename TReceiver, typename... TParam>
	class Slot : public SlotBase< TParam...>
	{
	public:
		using MemberFuncPointerType = void(TReceiver::*)(TParam...);
		Slot(TReceiver* ptrReceiver, MemberFuncPointerType ptrFunc)
		{
			m_ptrReceiver = ptrReceiver;
			m_ptrFunc = ptrFunc;
		}
	private:
		MemberFuncPointerType m_ptrFunc;
		TReceiver * m_ptrReceiver;
	};
}