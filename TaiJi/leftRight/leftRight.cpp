// leftRight.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <utility>
#include <thread>
#include <typeinfo>
using namespace std;

class CData
{
public:
	CData() = delete;
	CData(const char* ch) : data(ch)    // 构造函数，涉及资源的复制
	{
		std::cout << "CData(const char* ch)" << std::endl;
	}
	CData(const std::string& str) : data(str)  // 拷贝构造函数，涉及资源的复制
	{
		std::cout << "CData(const std::string& str)" << std::endl;
	}
	CData(std::string&& str) : data(str)    // 移动构造函数，不涉及资源的复制！！！
	{
		std::cout << "CData(std::string&& str)" << std::endl;
	}
	~CData()   // 析构函数
	{
		std::cout << "~CData()" << std::endl;
	}
private:
	std::string data;   // 表示类内部管理的资源
};
template<typename T>
CData* Creator(T&& t) { // 利用&&万能引用，引用折叠： T&& && -> T&&; T&& & -> T&
	return new CData(std::forward<T>(t));
}

template <typename T>
T ff(T&& x)
{
	return x;
}
void myFunc(int&& val)
{

}
int main()
{
	//示例代码1：
	/*std::cout << "示例代码1：" << std::endl;
	std::string str1 = "hello";
	std::string str2 = " world";
	CData* p1 = Creator(str1);
	CData* p2 = Creator(str1 + str2);*/
	//示例代码2：
	/*std::cout << "示例代码2：" << std::endl;
	int i = 1;
	int& j = i;
	int&& k = std::move(i);
	int p[10];
	std::cout << ff(i);*/

	int i = 100;
	myFunc(std::move(i)); // 需要把左值转化为右值
	myFunc(100);
	int &j = i;
	int&& r = 100;
	//myFunc(r);//r虽是右值引用，但实际上他是一个左值。
	//r = j;
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
