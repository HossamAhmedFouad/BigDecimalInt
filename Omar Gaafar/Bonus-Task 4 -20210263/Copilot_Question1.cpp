#include <bits/stdc++.h>
using namespace std;


// Create a function that takes a string and replace "He" with "He or She" and "he" with "he or she"  and "she" with "he or she" and "She" with "He or She".
// and "him"  with "him or her" and "Him" with "Him or Her"  and "Her"  with "Him or Her" and "her" with "him or her".
// Return the new string.
string replace(string str){
    string new_str = "";
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'H' && str[i+1] == 'e'){
            new_str += "He or She";
            i++;
        }
        else if(str[i] == 'h' && str[i+1] == 'e'){
            new_str += "he or she";
            i++;
        }
        else if(str[i] == 's' && str[i+1] == 'h' && str[i+2] == 'e'){
            new_str += "he or she";
            i += 2;
        }
        else if(str[i] == 'S' && str[i+1] == 'h' && str[i+2] == 'e'){
            new_str += "He or She";
            i += 2;
        }
        else if(str[i] == 'h' && str[i+1] == 'i' && str[i+2] == 'm'){
            new_str += "him or her";
            i += 2;
        }
        else if(str[i] == 'H' && str[i+1] == 'i' && str[i+2] == 'm'){
            new_str += "Him or Her";
            i += 2;
        }
        else if(str[i] == 'H' && str[i+1] == 'e' && str[i+2] == 'r'){
            new_str += "Him or Her";
            i += 2;
        }
        else if(str[i] == 'h' && str[i+1] == 'e' && str[i+2] == 'r'){
            new_str += "him or her";
            i += 2;
        }
        else{
            new_str += str[i];
        }
    }
    return new_str;
}

int main(){

    cout << replace("See an adviser and talk to him. He will guide you.") << endl;
}









