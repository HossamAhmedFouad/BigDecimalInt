/*
Name: Omar Gaafar
ID : 20210263
Problem Number : 4
Last Updated : 4/10/2022

*/


#include <iostream>

#include <string>

#include <cmath>

#include<bitset>
using namespace std;

void binaryPrint(int n)
{
    // Base Case
    if (n == 0)
    {
        cout << 0;
    }
    else
    {

        binaryPrint(n / 2);
        if (n == 1)
        {
            cout << '\b';
        }
        if (n % 2 == 0)
        {
            cout << '0';
        }
        else
        {
            cout << '1';
        }


    }


}


int k;
int& a = k;
// Function to generate all binary strings
void numbers(string prefix, int k)
{
    //Base Case
    if (k == 0)
    {
        cout << prefix + string(a, '0') << endl;
    }
    else
    {
        numbers(prefix, k - 1);
        cout << prefix;
        for (int i = a - 1; i >= 0; --i) {
            cout << bitset<2000>(k)[i];
        }
        cout << endl;

    }
}



int main()
{
    int selection;
    cout << "Enter Which Method you wish to use\n1 for One Binary Number\n2 for many binary numbers: ";
    cin >> selection;
    if (selection == 1)
    {
        int n;
        string bin = "";
        do
        {
            cout << "Enter a valid Decimal Number ";
            cin >> n;
        } while (n < 0);


        binaryPrint(n);

    }
    else
    {
        string prefix;

        cout << "Enter the prefix: ";
        cin >> prefix;

        do
        {
            cout << "Enter The Suffix: ";
            cin >> k;
        } while (k < 0);
        numbers(prefix, pow(2, k) - 1);
    }

}





