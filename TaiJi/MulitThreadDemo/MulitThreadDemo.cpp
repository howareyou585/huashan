// MulitThreadDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<thread>
#include <iostream>
#include <vector>
#include "ThreadFunc.h"
using namespace std;
int main()
{
    //1.测试当一个线程崩溃了，其他的线程是否会继续执行
    
   /* vector<thread> vecThread;
    for (int i = 0; i< 100; i++)
    {
        vecThread.emplace_back(thread(print,i));
    }
    thread divZeroThread(diveZero);
    divZeroThread.join();
    for (int i = 0; i < vecThread.size(); i++)
    {
        vecThread[i].join();
    }*/
    //2.测试两个线程读写同一个变量不冲突
    MsgQueque msgQueue;
    //thread inputThread(&MsgQueque::inputMsg, &msgQueue);
    //thread outputThread(&MsgQueque::outputMsg, &msgQueue);
    //3.测试两个线程死锁的场景
   /* thread inputThread(&MsgQueque::deadlockInputMsg, &msgQueue);
    thread outputThread(&MsgQueque::deadlockOutputMsg, &msgQueue);*/

    thread inputThread(&MsgQueque::uniqueLockInputMsg, &msgQueue);
    thread outputThread(&MsgQueque::uniqueLockOutputMsg, &msgQueue);
    inputThread.join();
    outputThread.join();
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
