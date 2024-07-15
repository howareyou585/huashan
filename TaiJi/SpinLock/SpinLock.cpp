#include "SpinLock.h"
using namespace std;
void SpinLock::lock()
{
	//条件为true:while 继续
	while (m_flg.test_and_set(std::memory_order_acquire));//自悬等待，直到成功获取到锁
}

void SpinLock::unlock() //释放锁
{
	m_flg.clear(std::memory_order_release);//m_flg 清0
	
}
