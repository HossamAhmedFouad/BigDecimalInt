/*
    Name : Mohamed Waleed Mohamed
    ID  : 20210362
    Assignment : 1
    Problem : 2

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string target, string delimiter)
{
    vector <string> v;
    while(target.find(delimiter) < 10000000)
    {
        int index = target.find(delimiter);
 
        string temp = target.substr(0, index);
        v.push_back(temp);
        target.erase(target.begin(), target.begin() + index + delimiter.size());
    }
    if (!target.empty())
        v.push_back(target);
    return v;
}

int main()
{
    vector <string> x;
    x =  split("do re mi fa so la ti do", " ");

    for (string s : x)
    {
        cout << s << " ";
    }
    
}