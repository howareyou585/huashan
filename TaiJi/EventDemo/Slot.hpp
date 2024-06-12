#pragma once
namespace Event
{
	template<typename TParam>
	class SlotBase
	{
	public:
		using FuncPointerType = void(*)(TParam);
		SlotBase() {}
		SlotBase(FuncPointerType ptrFunc)
		{
			m_ptrFunc = ptrFunc;
		}
		virtual void operator()(TParam par)
		{
			m_ptrFunc(par);
		}
	private:
		FuncPointerType m_ptrFunc;
	};

	template<typename TReceiver, typename TParam>
	class Slot : public SlotBase<TParam>
	{
	public:
		using MemberFuncPointerType = void(TReceiver::*)(TParam);
		Slot(TReceiver* ptrReceiver, MemberFuncPointerType ptrFunc)
		{
			m_ptrReceiver = ptrReceiver;
			m_ptrFunc = ptrFunc;
		}
		virtual void operator()(TParam par) override
		{
			(m_ptrReceiver->*m_ptrFunc)(par);
		}
	private:
		MemberFuncPointerType m_ptrFunc;
		TReceiver * m_ptrReceiver;
	};
}