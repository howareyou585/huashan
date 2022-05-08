#include "Person.h"
#include <iostream>
Person::Person(string name, string sex, int age)
{
	m_name = name;
	m_sex = sex;
	m_age = age;
}


Person::~Person()
{
	cout << "Person::~Person()" << endl;
}
