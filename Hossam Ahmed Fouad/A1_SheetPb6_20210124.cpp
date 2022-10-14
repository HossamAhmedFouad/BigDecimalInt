/**
 * author. Hossam Ahmed Fouad
 * Date: 14.10.22.
 * CS213 Assignment 1 - Sheet 1 problem 06
 */

#include <bits/stdc++.h>
using namespace std;

void fractalPattern( int n, int i ){
    if ( n == 0 ) return;
    fractalPattern( n/2, i); //Upper
    for ( int j = 0; j < i  ; j++ ) cout << "  ";
    for ( int j = 0; j < n; j++ ) cout << "* ";  //Central
    cout << endl;
    fractalPattern( n/2, i+n/2 ); // Lower
}

int main() {
    fractalPattern(8,0);
    return 0;
}
