#pragma once

void funcA();
#define PI 3.14;
class CPlusPlusClass
{
public:
    // ���Զ�C++ģ���ж����Class�ĵ���  
    int Add(int a, int b);
};
class Foo
{
public:
	void add(int* a, int* b, int* result);
	void spam1(Foo* x);  // ��ָ��
	void spam2(Foo& x);  // ������
	void spam3(Foo x);   // ��ֵ
	void spam4(Foo x[]); // ������
};
class Bar : public Foo
{

};
