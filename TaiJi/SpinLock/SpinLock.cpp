#include "SpinLock.h"
using namespace std;
void SpinLock::lock()
{
	//����Ϊtrue:while ����
	while (m_flg.test_and_set(std::memory_order_acquire));//�����ȴ���ֱ���ɹ���ȡ����
}

void SpinLock::unlock() //�ͷ���
{
	m_flg.clear(std::memory_order_release);//m_flg ��0
	
}
