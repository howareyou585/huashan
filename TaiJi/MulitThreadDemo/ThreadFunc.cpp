#include "ThreadFunc.h"
#include <iostream>
#include <thread>
using namespace std;
void print(int num)
{
	this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "thread id =" << num << std::endl;
}
void diveZero()
{
	int a = 100;
	int b = 0;
	int c = a / 0;
	cout << c << endl;
}