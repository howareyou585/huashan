#pragma once

void funcA();
#define PI 3.14;
class CPlusPlusClass
{
public:
    // 测试对C++模块中定义的Class的调用  
    int Add(int a, int b);
};
class Foo
{
public:
	void add(int* a, int* b, int* result);
	void spam1(Foo* x);  // 传指针
	void spam2(Foo& x);  // 传引用
	void spam3(Foo x);   // 传值
	void spam4(Foo x[]); // 传数组
};
class Bar : public Foo
{

};
