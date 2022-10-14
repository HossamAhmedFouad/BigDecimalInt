/*
Name: Omar Gaafar
ID : 20210263
Problem Number : 7
Last Updated : 4/10/2022

*/


#include <iostream>
#include <vector>
#include <string>
#include<string>
#include <map>
#include<algorithm>
#include <set>
#include <cmath>
#include <queue>
#include <list>
#include<unordered_map>
using namespace std;

bool bears(long long n);



int main()
{
	long long t;
	cout << "Enter how many cases you will need to check: ";
	cin >> t;
	while (t--)
	{
		long long n;
		cout << "Enter the number of bears: ";
		cin >> n;
		cout << (bears(n) ? "True" : "False") << endl;

	}


}
bool bears(long long n)
{

	if (n == 42)
	{
		return true;
	}
	if (n % 5 == 0 && n - 42 >= 42)
	{
		if (bears(n - 42))
		{
			return true;
		}
	}
	if (n % 2 == 0 && n / 2 >= 42)
	{
		if (bears(n / 2))
		{
			return true;
		}
	}
	if ((n % 3 == 0 || n % 4 == 0) && n - (n % 10 * (n % 100) / 10) >= 42 && (n % 10 * (n % 100) / 10) != 0)
	{
		if (bears(n - (n % 10 * (n % 100) / 10)))
		{
			return true;
		}
	}
	return false;
}


