#include <memory>
#include<iostream>
#include<vector>
#include "Person.h"
using namespace std;
void print(shared_ptr<int> p)
{
	cout << *p << endl;
}
//����ָ�����壺
//��ʹ����ͬ������ָ��ֵ��ʼ������reset���������ָ�롣
//��delete get()���ص�ָ��
//��ʹ��get()��ʼ����reset��һ������ָ��
//�����ʹ��get()���ص�ָ�룬��ס�����һ����Ӧ������ָ�����ٺ����ָ��ͱ�Ϊ��Ч��
//�����ʹ������ָ��������Դ����new������ڴ棬��ס���ݸ���һ��ɾ������

int main()
{
	//1.�����е�Ԫ��Ϊ����ָ�룬
	
	vector<shared_ptr<Person>> vecPerson;
	vecPerson.push_back( make_shared<Person>("gcy", "male", 39));
	vecPerson[0] = make_shared<Person>("likun", "male", 36);
	//ִ�к�Ĵ�ӡ��Ϣ��name:gcy, Person::~Person()=>�������е�Ԫ�ر�������Ԫ���滻�󣬸�Ԫ�ص����ü���-1
	
	vector<shared_ptr<Person>> verPerson2;
	shared_ptr<Person> person2 = make_shared<Person>("zyp", "male", 40);
	verPerson2.push_back(person2); // ִ�к�person2�����ü���Ϊ2
	//2.���û�������ָ������ָͨ��
	shared_ptr<int> ptrInt = make_shared<int>(23);
	/*int* p = ptrInt.get();
	{
		shared_ptr<int> qtrInt(p); 
	}*/
	// �ڴ��ͷ���qtrInt��ptrInt�Ĺ���ѿռ�
	//*p = 10; // �쳣��p�Ķѿռ���ǰ���ͷ�...
	//*ptrInt = 100; // �쳣��ptrInt�Ķѿռ���ǰ���ͷ�...

	shared_ptr<Person> person3 = make_shared<Person>("zhangsan", "male", 20);
	
	cout << "test finish!" << endl;
	//3.����weak_ptr�ļ��ַ�ʽ
	weak_ptr<int> wp1 ;
	wp1 = ptrInt;
	weak_ptr<int> wp2 = wp1;
	
	//�� wp1 Ϊ��ָ�룬�� wp2 ҲΪ��ָ�룻
	//��֮����� wp1 ָ��ĳһ shared_ptr ָ��ӵ�еĶ��ڴ棬
	//�� wp2 Ҳָ��ÿ�洢�ռ䣨���Է��ʣ���������Ȩ����
	
	return 0;
}