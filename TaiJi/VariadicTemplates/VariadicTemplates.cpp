// VariadicTemplates.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

//1.第一种方式 ：使用无参递归终止函数
void myPrint()
{
    cout << endl;
}
template < typename T1, typename ...T2>
void myPrint(T1 t1, T2... t2)
{
    cout << t1<<",";
    myPrint(t2...);
}
//2.第二种方式：两个函数模板，区别是模板参数的区别：当两个参数模板都适用某种情况时，
//优先使用没有“template parameter pack”的版本
template <typename T>
void myFunc(T t)
{
    cout << t << endl;
}

template <typename T1 ,typename ...T2>
void myFunc(T1 t1, T2 ... t2)
{
    cout << t1 << ",";
    myFunc(t2...);
}

int main()
{
    //1.使用第一种方式：无参终止函数
    myPrint(2, 4, 5, 6);
    myFunc(6, 5, 4, 2);
    return 0;
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
