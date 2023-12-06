#include "ShowCase.h"
#include <vcclr.h>

using namespace System;
using namespace CShapeDll;
gcroot<ShowCase^> _showCase = gcnew ShowCase();

int CShowCase::Sum(int a, int b)
{
    return _showCase->Sum(a, b);
}

LPCWSTR CShowCase::GetFullName(LPCWSTR firstName, LPCWSTR lastName)
{
    auto firstNameStr = gcnew System::String(firstName);
    auto lastNameStr = gcnew System::String(lastName);
    auto str = _showCase->GetFullName(firstNameStr, lastNameStr);
    pin_ptr<const WCHAR> nativeStr = PtrToStringChars(str);
    return (LPCWSTR)nativeStr;
}