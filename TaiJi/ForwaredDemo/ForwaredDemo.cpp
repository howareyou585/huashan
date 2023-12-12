// ForwaredDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;
using namespace std;
void myFunc(int v1, int v2)
{
	++v2;
	cout << "v1+v2=" << v1 + v2 << endl;
}

void myFuncRef(int v1, int&v2)
{
	++v2;
	cout << "v1+v2=" << v1 + v2 << endl;
}

void myFuncRef2(int&& v1, int &v2)
{
	std::cout << "v1=" <<v1<< endl;
	std::cout << "v2=" << v2 << endl;
}

template<typename F, typename T1, typename T2>
void myFuncTemp(F f, T1 t1, T2 t2)
{
	f(t1, t2);
}

template<typename F , typename T1 , typename T2>
void myFuncTempForUniserval(F f, T1&& t1, T2&& t2)
{
	f(t1, t2);
}
template <typename F, typename T1, typename T2>
void myFuncTempForFroward(F f, T1&& t1, T2 && t2)
{
	f(std::forward<T1>(t1),std::forward<T2>(t2));
}

void printInfo(int & t)
{
	cout << "printT()参数类型为左值引用" << endl;
}
void printInfo(int&& t)
{
	cout << "printT()参数类型为右值引用" << endl;
}

template <typename T>
void TestF(T&& t)
{
	std::cout << "T=" << type_id_with_cvr<T>().pretty_name() << std::endl;
	std::cout << "paramval type = " << type_id_with_cvr <decltype(t)>().pretty_name() << std::endl;
	std::cout << endl;
	printInfo(t);
	printInfo(std::forward<T>(t));
	printInfo(std::move(t));
}

int main()
{
	int j = 70;
	int i = 20;
	//myFuncTemp(myFunc, 20, j);
	//myFuncTemp(myFuncRef, 20, j);
	//myFuncTempForUniserval(myFuncRef, i, j);
	//myFuncTempForUniserval(myFuncRef2, 20, j); //报错，20 为右值，被绑定到右值引用后，重新转发为左值了。
	//myFuncTempForFroward(myFuncRef2, 20, j);
	
	TestF(20);
	cout << "------------------------------------------" << endl;
	TestF(i);
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
