#pragma once

class SimpleCallback
{
public:
	SimpleCallback();
	virtual  ~SimpleCallback();
	virtual void run();
};
class Caller
{
private:
	SimpleCallback* m_ptrCallback;
public:
	Caller();
	virtual ~Caller();
	void setCallback(SimpleCallback* ptrCallback);
	void resetCallback();
	SimpleCallback* getCallBack();
	void call();

};
