
#include "CPlusPlusClass.h"
#include <iostream>

using namespace std;
int a = 0;
int CPlusPlusClass::Add(int a, int b)
{
    return a + b;
}

void funcA()
{
    cout << "invoke funcA" << endl;
}

void Foo::add(int* a, int* b, int* result)
{
    *result = *a + *b;
}

void Foo::spam1(Foo* x)
{
    
}

void Foo::spam2(Foo& x)
{
}

void Foo::spam3(Foo x)
{
}

void Foo::spam4(Foo x[])
{
}
