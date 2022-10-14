/*
    Name : Mohamed Waleed Mohamed
    ID  : 20210362
    Assignment : 1
    Problem : 8

*/
#include <iostream>
#include "smart_array.cpp"
using namespace std;




int main()
{      //char, string, int
    Array <int> sonk(7);
    for (int i = 0; i < 7; i++){
        cin >> sonk[i];
    }
    Array <int> bonk;
    Array <int> zonk(sonk);
    for (int i = 0; i < 7; i++){
        cout << sonk[i] << " ";
    }
    cout << endl;
    cout << sonk.size() << endl;

    bonk = sonk;
    for (int i = 0; i < 7; i++){
        cout << bonk[i] << " ";
    }
        cout << bonk.size() << endl;
}
