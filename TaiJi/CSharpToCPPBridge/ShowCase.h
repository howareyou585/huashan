#pragma once
#include <Windows.h>
#ifdef CSHARPTOCPPBRIDGE_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

#ifndef EXAMPLE_OBJECT_H
#define EXAMPLE_OBJECT_H

class DLLEXPORT  CShowCase
{
public:
    /// <summary>
    /// Get sum of two numbers;
    /// </summary>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <returns></returns>
    int Sum(int a, int b);

    /// <summary>
    ///  Get full name;
    /// </summary>
    /// <param name="firstName"></param>
    /// <param name="lastName"></param>
    /// <returns></returns>
    LPCWSTR GetFullName(LPCWSTR firstName, LPCWSTR lastName);
};
#endif

