// DumpDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "tchar.h"
#include <iostream>
#include <Windows.h>
#include <DbgHelp.h>
#include <string>
using namespace std;
#pragma comment(lib, "dbghelp.lib")

int division(int denominator);
LONG WINAPI handleException(LPEXCEPTION_POINTERS lpExceptionInfo);
INT generateMiniDump(PEXCEPTION_POINTERS exception_pointers);
std::wstring stringToWString(const std::string& str);
int main(int argc, char* argv[])
{
    
    SetUnhandledExceptionFilter(handleException);

    printf("the result is %d\r\n", division(atoi(argv[1])));  //显示结果

    system("pause");
    Sleep(1000);
}
int division(int denominator)
{
    int fRet = 100 / denominator;
    return fRet;
}
LONG WINAPI handleException(LPEXCEPTION_POINTERS lpExceptionInfo)
{
    auto res = generateMiniDump(lpExceptionInfo);
    // #TODO: 可以尝试做一些事情
    return res;

}
INT generateMiniDump(PEXCEPTION_POINTERS exception_pointers)
{
    //1.获取进程ID
    auto pid = GetCurrentThreadId();
    char fileName[MAX_PATH] = {};
    //2.获取当前事件
    SYSTEMTIME systemtime;
    GetLocalTime(&systemtime);
    sprintf_s(fileName, MAX_PATH, "%s--%04d%02d%02d-%02d%02d%02d.dmp", (char*)(to_string(pid).c_str()), 
        systemtime.wYear, systemtime.wMonth, 
        systemtime.wDay, systemtime.wHour, 
        systemtime.wMinute, systemtime.wSecond);
    string dumpFile(fileName); //dump文件的名称
    
    HANDLE hFile = CreateFile(stringToWString(dumpFile).c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE, nullptr,
        CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile)
    {
        return EXCEPTION_CONTINUE_EXECUTION;
    }
    MINIDUMP_EXCEPTION_INFORMATION exceptionInformation{};
    exceptionInformation.ThreadId = pid;
    exceptionInformation.ExceptionPointers = exception_pointers;
    exceptionInformation.ClientPointers = FALSE;
    // 建议 MiniDumpWithFullMemory(将会很大!!!) 或者 MiniDumpNormal(文件小,功能够用)
    MiniDumpWriteDump(GetCurrentProcess(), pid, hFile, MiniDumpNormal, (exception_pointers ? &exceptionInformation : nullptr), nullptr, nullptr);
    CloseHandle(hFile);
    return EXCEPTION_EXECUTE_HANDLER;
}

std::wstring stringToWString(const std::string& str)
{
    std::wstring szStr;
    int nLength = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
    szStr.resize(nLength);
    wchar_t* lpszStr = new wchar_t[nLength];
    MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, lpszStr, nLength);
    szStr = lpszStr;
    delete[] lpszStr;
    return szStr;
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
