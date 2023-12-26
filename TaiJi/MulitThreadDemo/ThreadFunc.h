#pragma once
#include <vector>
#include <list>
#include <queue>
#include <mutex>
using namespace std;
void print(int num);
void diveZero();
class MsgQueque
{
public:
	void inputMsg();
	void outputMsg();
	void deadlockInputMsg();
	void deadlockOutputMsg();
	void uniqueLockInputMsg();
	void uniqueLockOutputMsg();
private:
	bool outMsgLULProc(int & command);
private:
	list<int> queNumber;
	mutex m_mutex_a;
	mutex m_mutex_b;
};
