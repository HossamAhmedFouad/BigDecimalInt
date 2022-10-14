/**
 * author. Hossam Ahmed Fouad
 * Date: 14.10.22.
 * CS213 Assignment 1 - Sheet 1 problem 00
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    //Maximum number of characters
    const int MAX_CHARACTERS = 100;
    string line{};
    //Take full line of input
    getline(cin,line,'.');
    //Take limit up to 100 Character
    int limit = min((int)line.size(),MAX_CHARACTERS);
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
