#pragma once
#include<string>
using namespace std;
class Person
{
public:
	Person(string name, string sex, int age);
	~Person();
private:
	string m_name;
	string m_sex;
	int m_age;
};

