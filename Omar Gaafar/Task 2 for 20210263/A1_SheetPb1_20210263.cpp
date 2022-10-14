/*
Name: Omar Gaafar
ID : 20210263
Problem Number : 1 
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


string him_her(string text);


string he_she(string text);


int main()
{
	
	string text;
	cout << "Enter the text: ";
	getline(cin, text);
		

		text = him_her(text);
		text = he_she(text);
		cout << text << endl;
	

}


string him_her(string text)
{
	string str;
	for (int i = 0; i < text.length() ; i++)
	{
		
		if ((text[i] == 'h' ) && text[i + 1] == 'i' && text[i + 2] == 'm' && (!isalpha(text[i + 3]) && !isdigit(text[i + 3])))
		{
			str += "him or her";
			i += 2;
		}
		else if  ((text[i] == 'H') && text[i + 1] == 'i' && text[i + 2] == 'm' && (!isalpha(text[i + 3]) && !isdigit(text[i + 3])))
		{
			str += "Him or Her";
			i += 2;
		}
		else if ((text[i] == 'h' ) && text[i + 1] == 'e' && text[i + 2] == 'r' && (!isalpha(text[i + 3]) && !isdigit(text[i + 3])))
		{
			str += "him or her";
			i += 2;
		}
		else if ((text[i] == 'H') && text[i + 1] == 'e' && text[i + 2] == 'r' && (!isalpha(text[i + 3]) && !isdigit(text[i + 3])))
		{
			str += "Him or Her";
			i += 2;
		}
		else
		{
			str += text[i];
		}
	}
	

	return str;

}

string he_she(string text)
{
	string str;
	
	for (int i = 0; i < text.length() ; i++)
	{
		if ((text[i] == 'h'  && text[i + 1] == 'e' && !isalpha(text[i + 2]) && !isdigit(text[i + 2])))
		{
			str += "he or she";
			i += 1;
		}
		else if ((text[i] == 'H' && text[i + 1] == 'e' && !isalpha(text[i + 2]) && !isdigit(text[i + 2])))
		{
			str += "He or She";
				i += 1;
		}
		else if ((text[i] == 's' ) && text[i + 1] == 'h' && text[i + 2] == 'e' && !isalpha(text[i + 3]) && !isdigit(text[i + 3]))
		{
			str += "he or she";
			i += 2;
		}
		else if ((text[i] == 'S') && text[i + 1] == 'h' && text[i + 2] == 'e' && !isalpha(text[i + 3]) && !isdigit(text[i + 3]))
		{
			str += "He or She";
			i += 2;
		}
		else
		{
			str += text[i];
		}
	}
	

	return str;
}
