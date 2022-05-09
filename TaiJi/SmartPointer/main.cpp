#include <memory>
#include<iostream>
#include<vector>
#include "Person.h"
using namespace std;
void print(shared_ptr<int> p)
{
	cout << *p << endl;
}
//智能指针陷阱：
//不使用相同的内置指针值初始化（或reset）多个智能指针。
//不delete get()返回的指针
//不使用get()初始化或reset另一个智能指针
//如果你使用get()返回的指针，记住当最后一个对应的智能指针销毁后，你的指针就变为无效了
//如果你使用智能指针管理的资源不是new分配的内存，记住传递给它一个删除器。

int main()
{
	//1.容器中的元素为智能指针，
	
	vector<shared_ptr<Person>> vecPerson;
	vecPerson.push_back( make_shared<Person>("gcy", "male", 39));
	vecPerson[0] = make_shared<Person>("likun", "male", 36);
	//执行后的打印信息：name:gcy, Person::~Person()=>当容器中的元素被其他的元素替换后，该元素的引用计数-1
	
	vector<shared_ptr<Person>> verPerson2;
	shared_ptr<Person> person2 = make_shared<Person>("zyp", "male", 40);
	verPerson2.push_back(person2); // 执行后person2的引用计数为2
	//2.不用混用智能指针与普通指针
	shared_ptr<int> ptrInt = make_shared<int>(23);
	/*int* p = ptrInt.get();
	{
		shared_ptr<int> qtrInt(p); 
	}*/
	// 在此释放了qtrInt与ptrInt的共享堆空间
	//*p = 10; // 异常，p的堆空间在前面释放...
	//*ptrInt = 100; // 异常，ptrInt的堆空间在前面释放...

	shared_ptr<Person> person3 = make_shared<Person>("zhangsan", "male", 20);
	
	cout << "test finish!" << endl;
	//3.创建weak_ptr的几种方式
	weak_ptr<int> wp1 ;
	wp1 = ptrInt;
	weak_ptr<int> wp2 = wp1;
	
	//若 wp1 为空指针，则 wp2 也为空指针；
	//反之，如果 wp1 指向某一 shared_ptr 指针拥有的堆内存，
	//则 wp2 也指向该块存储空间（可以访问，但无所有权）。
	
	return 0;
}