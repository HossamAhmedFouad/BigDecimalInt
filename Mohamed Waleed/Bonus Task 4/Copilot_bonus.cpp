/*
    Name : Mohamed Waleed Mohamed
    ID  : 20210362
    Assignment : 1
    Bonus task 4

*/

#include <iostream>
#include <vector>
using namespace std;

// vector of string splitted with a string delimiter and returns the vector
std::vector<std::string> split(std::string target, std::string delimiter)
{
    std::vector <std::string> v;
    while(target.find(delimiter) < 10000000)
    {
        int index = target.find(delimiter);
 
        std::string temp = target.substr(0, index);
        v.push_back(temp);
        target.erase(target.begin(), target.begin() + index + delimiter.size());
    }
    if (!target.empty())
        v.push_back(target);
    return v;
}

int main(){
    vector <string> v = split("do re mi fa so la ti do", " ");
    for (string s : v)
    {
        cout << s << " ";
    }
}


