// SignalSlotMechanism.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Event.hpp"
class A {
public :
    void addA(int a , int b)
    {
        int sum = a + b;
        cout << "invoke A::addA  a+b = " << sum << endl;
    }
    void subA(int a, int b)
    {
        int sub = a - b;
        cout << "invoke A::subA  a-b = " << sub << endl;
    }
};
void add(int a, int b)
{
    int sum = a + b;
    cout << "invoke add  a+b= " << sum << endl;
}
void sub(int a, int b)
{
    int ret = a - b;
    cout << "inkoke sub a-b = " << ret << endl;
}
int main()
{
    //A* ptra = new A();
    A a;
    Event<int,int> e;
    vector<unsigned long> vecSignalId;
    vecSignalId.emplace_back(e.connect(add));
    vecSignalId.emplace_back(e.connect_member(&a, &A::addA));
    e.connect(sub);
    e.connect_member(&a, &A::subA);
    e.emit(2,6);
    //vecSignalId.erase(vecSignalId.begin());
   
    cout << endl;
    e.emit_for_all_but_some(2, 6, vecSignalId);
    cout << endl;
    e.emit_for(2, 6, vecSignalId);
    
    //e.disconnect();
   /* if (ptra)
    {
        delete ptra;
        ptra = nullptr;
    }*/
    std::cout << "Hello World!\n";
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
