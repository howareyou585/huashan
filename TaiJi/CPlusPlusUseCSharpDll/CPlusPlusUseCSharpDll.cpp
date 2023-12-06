// CPlusPlusUseCSharpDll.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <mscoree.h>
#include <metahost.h>
#include <assert.h>
#include "stdlib.h"
#include "ShowCase.h"
#pragma comment(lib, "mscoree.lib")
#define BUFFER_SIZE 500
using namespace std;

int main()
{
    auto showCase = new CShowCase();
    auto sum = showCase->Sum(3, 5);
    cout << "3+5=" << sum << endl;
    auto firstName = L"Billy";
    auto lastName = L"Herrington";
    auto fullName = showCase->GetFullName(firstName, lastName);
    cout << "Full name is " << fullName << endl;
    delete showCase;
    
    //ICLRMetaHost* pMetaHost = nullptr;
    //ICLRMetaHostPolicy* pMetaHostPolicy = nullptr;
    //ICLRRuntimeHost* pRuntimeHost = nullptr;
    //ICLRRuntimeInfo* pRuntimeInfo = nullptr;
    //do {
    //    HRESULT hr = CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID*)&pMetaHost);
    //    hr = pMetaHost->GetRuntime(L"v4.0.30319", IID_PPV_ARGS(&pRuntimeInfo));

    //    if (FAILED(hr))
    //    {
    //        break;
    //    }

    //    hr = pRuntimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_PPV_ARGS(&pRuntimeHost));

    //    hr = pRuntimeHost->Start();

    //    DWORD dwRet = 0;
    //   /* hr = pRuntimeHost->ExecuteInDefaultAppDomain(L"SampleManagedApp.exe",
    //        L"SampleManagedApp.Program",
    //        L"Test",
    //        L"Hello World!",
    //        &dwRet);*/
    //    hr = pRuntimeHost->ExecuteInDefaultAppDomain(L"CShapeDll.dll",
    //        L"CShapeDll.Test",
    //        L"Add",
    //        L"5,3",
    //        &dwRet);
    //  

    //    hr = pRuntimeHost->Stop();
    //} while (0);


    //if (pRuntimeInfo != nullptr)
    //{
    //    pRuntimeInfo->Release();
    //    pRuntimeInfo = nullptr;
    //}

    //if (pRuntimeHost != nullptr)
    //{
    //    pRuntimeHost->Release();
    //    pRuntimeHost = nullptr;
    //}

    //if (pMetaHost != nullptr)
    //{
    //    pMetaHost->Release();
    //    pMetaHost = nullptr;
    //}
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
