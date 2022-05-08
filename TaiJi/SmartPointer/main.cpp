#include <memory>
#include<iostream>
#include<vector>
#include "Person.h"
using namespace std;
void print(shared_ptr<int> p)
{
	cout << *p << endl;
}
int main()
{
	using PString = std::unique_ptr<string>;
	vector<PString> vec;
	string word;
	vec.reserve(100);
	while (true)
	{
		if ((std::cin >> word).eof())
		{
			std::cin.clear();
			break;
		}
		vec.push_back(make_unique<string>(word));
	}
	
	return 0;
}