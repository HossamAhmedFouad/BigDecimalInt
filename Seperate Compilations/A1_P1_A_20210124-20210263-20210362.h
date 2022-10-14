/*
    Last modified : 2022/10/06
    Made by : Mohamed Waleed/ Omar Gaafar/ Hossam Ahmed fouad
                 20210362   / 20210263  / 20210124
*/
#ifndef NEW_A1_P1_A_20210124_20210263_20210362_H
#define NEW_A1_P1_A_20210124_20210263_20210362_H

#endif //NEW_A1_P1_A_20210124_20210263_20210362_H

#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

class BigDecimalInt {
private:
    string number;
    char num_sign;
    int sz;


public:
    // Empty constructor with default value 0;
    BigDecimalInt();

    // Constructor to initialize from integer
    BigDecimalInt(int n);

    // Constructor to initialize from string
    BigDecimalInt(string n);
    bool checkValidity() ;

    friend BigDecimalInt operator+(const BigDecimalInt& a, const BigDecimalInt& b);

    friend BigDecimalInt operator - (const BigDecimalInt& a, const BigDecimalInt& b) ;

    friend bool operator< (const BigDecimalInt& a, const BigDecimalInt& b);
    friend bool operator> (const BigDecimalInt& a, const BigDecimalInt& b);

    friend bool operator== (const BigDecimalInt& a, const BigDecimalInt& b);

    BigDecimalInt operator= (const BigDecimalInt& a);


    int size() ;


    char sign() ;


    char getSign() ;
    string getNumber();
    int getSize();

    ~BigDecimalInt() {};
};

//k
ostream& operator << (ostream& out, BigDecimalInt a);

