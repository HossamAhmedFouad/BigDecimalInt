/**
 * Author : Hossam Ahmed Fouad
 * Date : 14.10.22
 * CS213 Assignment 1 - Task 4 Bonus
 */

#include <bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;


int main() {
    //Take from user up to 100 character or until a dot
    string line{};
    getline(cin,line,'.');
    //Take up to 100 character
    int limit = min((int)line.size(),100);
    //Store words separately
    vector<string>words{};
    //Collect chars of every word
    string word{};
    for(int i=0;i<limit;i++){
        //Collect char if not a space
        if(!isspace(line[i])){
            char x = line[i];
            if(isalpha(x)) x = tolower(x);
            word.push_back(x);
            //Add collected char
        }else{
            if(!word.empty()) words.push_back(word);
            word.clear();
        }
    }
    if(!word.empty()) words.push_back(word);
    //Capitalize first letter in sentence if it is a letter
    if(isalpha(words[0][0])) words[0][0] = toupper(words[0][0]);
    words[words.size()-1].push_back('.');
    for(auto &x : words) cout<<x<<" ";


    return 0;
}

