/*
    Last modified : 2022/10/05
    Made by : Mohamed Waleed/ Omar Gaafar/ Hossam Ahmed fouad
                 20210362   / 20210263  / 20210124

*/






#include <iostream>
using namespace std;

class BigDecimalInt{
private:
    string number;
    char num_sign;
    // int num_sign; //1 = +ve  and -1 = -ve
    int sz;


public:
    // Empty constructor with default value 0;
    BigDecimalInt(){
        number = "\0";
        num_sign = '\0';
        sz = 0;
    }
    // Constructor to initialize from integer
    BigDecimalInt(int n){
        number = to_string(n);

        if (!checkValidity()){
            cout << "invalid, value set to 0" << endl;
            number = "0";
            num_sign = '\0';
        }
        else
        {
            num_sign = sign();
            sz = size();
        }
    }
    // Constructor to initialize from string
    BigDecimalInt(string n){
        number = n;

        if (!checkValidity()){
            cout << "invalid, value set to 0" << endl;
            number = "0";
            num_sign = '\0';
        }
        else
        {
            num_sign = sign();
            sz = size();
        }

    }


    // Check if its valid | works
    bool checkValidity(){
        for (int i = 0; i < number.size(); i++)
        {
            char c = number[i];
            if ((c == '+' || c == '-') && i != 0 || c == ' ')
                return false;
        }
        return true;
    }
    //f
    friend bool operator> (const BigDecimalInt& a, const BigDecimalInt& b)
    {
        if (a.sz > b.sz)
            return true;
        else if (a.sz < b.sz)
            return false;
        else
        {
            for (int i = 0; i < a.sz; i++)
            {
                if (a.number[i] > b.number[i])
                    return true;
                else if (a.number[i] < b.number[i])
                    return false;
            }

        }
        return false;
    }
    //g
    friend bool operator== (const BigDecimalInt& a,const BigDecimalInt& b)
    {
        if (a.number != b.number || a.num_sign != b.num_sign)
            return false;
        else
            return true;
    }

    // //h
    // BigDecimalInt operator= (BigDecimalInt b)
    // {
    //     BigDecimalInt c;
    //     c.number = b.getNumber();
    //     c.num_sign = b.getSign();
    //     c.sz = b.getSize();
    //     return c;
    // }

    //i
    int size(){
        if (!isdigit(number[0]))
            number.erase(number.begin());
        return number.size();
    }

    //j
    char sign(){
        if (isdigit(number[0]) || number[0] == '+')
            num_sign = '+';
        else
            num_sign = '-';

        return num_sign;
    }

    //getters
    char getSign(){
        return num_sign;
    }
    string getNumber(){
        return number;
    }
    int getSize(){
        return sz;
    }
    // Destructor
    ~BigDecimalInt(){}
};

//k
ostream& operator << (ostream& out, BigDecimalInt a)
{
    if (a.getSign() == '-')
        cout << a.getSign();
    cout << a.getNumber();
    return out;
}

int main()
{
    int n = 1;
    while (n--)
    {
        BigDecimalInt x;
        BigDecimalInt y = {"12"};
        BigDecimalInt z = {1350};
        x = y;



        // cout << y << endl;             // the overloaded operator <<  printed -12 as -12
        // cout << y.getNumber() << endl; // holds value without signs  -12 is stored as 12 but printed as -12
        // cout << y.getSign() << endl;   // holds the sign + or -
        // cout << y.getSize() << endl;   // holds the size
    }
}
