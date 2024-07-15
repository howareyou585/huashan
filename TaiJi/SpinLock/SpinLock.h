#ifndef _SPIN_LOCK_H
#define _SPIN_LOCK_H
#include <atomic>
//зда§Ыј
class SpinLock
{
public:
	void lock();
	void unlock();
private:
	std::atomic_flag m_flg= ATOMIC_FLAG_INIT;
};
#endif // 