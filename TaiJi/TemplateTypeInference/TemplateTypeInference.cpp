// TemplateTypeInference.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <boost/type_index.hpp>
using namespace boost::typeindex;
using namespace std;
template<typename T>
void funcPassVal(T paramVal)
{
    std::cout << "T = " << type_id<T>().pretty_name() << std::endl;
    std::cout << "paramval type = " << type_id <decltype(paramVal)>().pretty_name() << std::endl;
    paramVal += 10;
    std::cout << "paramVal=" << paramVal << endl;
}

template<typename T>
void funcPassConstVal(const T paramVal)
{
    std::cout << "T = " << type_id<T>().pretty_name() << std::endl;
    std::cout << "paramval type = " << type_id <decltype(paramVal)>().pretty_name() << std::endl;
}

template<typename T>
void funcPassRef(T& paramval)
{
   
    std::cout << "T = " << type_id<T>().pretty_name() << std::endl;
    std::cout << "paramval type = " << type_id <decltype(paramval)>().pretty_name() << std::endl;
}
template<typename T>
void funcPassConstRef(const T& paramval)
{
   
    std::cout << "T = " << type_id<T>().pretty_name() << std::endl;
    std::cout << "paramval type = " << type_id <decltype(paramval)>().pretty_name() << std::endl;
}
int main()
{
    //std::cout << "Hello World!\n";
    int a = 10;
    int& b = a;
    const int& c = a;
    const int d = 10;
    cout << "invoke funcPassVal" << endl;
    //const 值
    funcPassVal(a);  //T int <====> paramVal int
    cout << a << endl;
    funcPassVal(b);  //T int <====> paramVal int   引用会被忽略 
    cout << b << endl; 
    funcPassVal(c);  //T int <====> paramVal int   引用会被忽略  const 也会被忽略
    cout << c << endl;
    funcPassVal(d);  //T int <====> paramVal int   const 会被忽略
    cout << d << endl;
    cout << endl;
    
    
    //引用
    cout << "invoke funcPassConstVal" << endl;
    funcPassConstVal(a);  //T int <====> paramVal int
    funcPassConstVal(b);  //T int <====> paramVal int   引用会被忽略 
    funcPassConstVal(c);  //T int <====> paramVal int   引用会被忽略  const 也会被忽略
    funcPassConstVal(d);  //T int <====> paramVal int   const 会被忽略

    cout << endl;
    cout << "invoke funcPassRef" << endl;

    funcPassRef(a);  //T int <====> paramVal int
    funcPassRef(b);  //T int <====> paramVal int   引用会被忽略 
    funcPassRef(c);  //T int <====> paramVal int   引用会被忽略  const 也会被忽略
    funcPassRef(d);  //T int <====> paramVal int   const 会被忽略

    /*std::cout << "invoke func" << std::endl;
    func(a);
    func(b);
    func(c);
    func(d);
    std::cout << "invoke funcConst" << std::endl;
    funcConst(10);
    funcConst(a);
    funcConst(b);*/
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
