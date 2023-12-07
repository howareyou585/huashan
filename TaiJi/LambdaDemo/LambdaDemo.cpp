// LambdaDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item
{
	Item(int a, int b) :_a(a), _b(b) {}
	int _a;
	int _b;

};

int main()
{
   //1.简单的例子
	cout << "lambda 简单的用法" << endl;
	auto plus = [](int v1, int v2)->int {return v1 + v2; };
	int c = plus(3, 6);
	std::cout << "a + b = " << c << std::endl;
	//2.lambda 回调
	std::vector<Item> vec;
	vec.push_back(Item(1, 19));
	vec.push_back(Item(10, 3));
	vec.push_back(Item(3, 7));
	vec.push_back(Item(8, 12));
	vec.push_back(Item(2, 1));
	std::sort(vec.begin(), vec.end(),
		[](const Item& v1, const Item& v2) { return v1._a < v2._a; });

	std::for_each(vec.begin(), vec.end(), [](Item& v) {cout << v._a << "  " << v._b << endl; });

	//3.值捕获时，没有mutable关键字是无法修改捕获的值的，哪怕这个修改不会改变lambda表达式外部的变量；
	//值捕获时，如果要修改捕获的值，要添加关键字mutable
	cout << "值捕获时mutable的用法" << endl;
	int x = 1;
	int y = 2;
	auto plus2 = [=](int v1, int v2) mutable->int {x++; return x+y+v1 + v2; };
	int c2 = plus2(3, 6);
	cout << "x+y+v1+v2=" << c2 << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
