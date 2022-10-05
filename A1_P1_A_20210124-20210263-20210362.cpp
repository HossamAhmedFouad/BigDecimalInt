/*
    Last modified : 2022/10/05
    Made by : Mohamed Waleed/ Omar Gaafar/ Hossam Ahmed fouad
                 20210362   / 20210263  / 20210124

*/
#include <iostream>
using namespace std;

class BigDecimalInt {
private:
    string number;
    char num_sign;
    // int num_sign; //1 = +ve  and -1 = -ve
    int sz;


public:
    // Empty constructor with default value 0;
    BigDecimalInt() {
        number = "\0";
        num_sign = '\0';
        sz = 0;
    }

    // Constructor to initialize from integer
    BigDecimalInt(int n) {
        number = to_string(n);

        if (!checkValidity()) {
            cout << "invalid, value set to 0" << endl;
            number = "0";
            num_sign = '\0';
        } else {
            num_sign = sign();
            sz = size();
        }
    }

    // Constructor to initialize from string
    BigDecimalInt(string n) {
        number = n;

        if (!checkValidity()) {
            cout << "invalid, value set to 0" << endl;
            number = "0";
            num_sign = '\0';
        } else {
            num_sign = sign();
            sz = size();
        }

    }


    // Check if its valid | works
    bool checkValidity() {
        for (int i = 0; i < number.size(); i++) {
            char c = number[i];
            if ((!isdigit(c)) && i != 0 || c == ' ')
                return false;
        }
        return true;
    }
    //f

    friend BigDecimalInt operator+(const BigDecimalInt &a, const BigDecimalInt &b) {
        BigDecimalInt first_number{},second_number{};
        //----Subtraction Operations
        if(a.num_sign=='-' && b.num_sign=='-'){
            second_number = b;
            second_number.num_sign = '+';
            return a - second_number;
        }else if(a.num_sign=='+' && b.num_sign=='-'){
            return a - b;
        }else if(a.num_sign=='-' && b.num_sign=='+'){
            return b - a;
        //--------------------------
        }else{
            //Assign the greater number to the first number
            if(a.sz>b.sz){
                first_number = a;
                second_number = b;
            }else{
                first_number = b;
                second_number = a;
            }
            BigDecimalInt result{};
            int carry = 0;
            int digit_sum{};
            int delta = first_number.sz-second_number.sz;
            //Add the two numbers digit by digit and maintain the carry count
            for(int i=second_number.sz-1;i>0;i--){
                digit_sum = (first_number.number[i+delta]-'0') + (second_number.number[i]-'0') + int(carry>0);
                carry -= carry>0;
                if(digit_sum>9){
                    carry++;
                    digit_sum-=10;
                }
                result.number = to_string(digit_sum) + result.number;
            }
            //If they are the same length of digits output the final digit without carry
            if(first_number.sz==second_number.sz){
                digit_sum = (first_number.number[0]-'0') + (second_number.number[0]-'0') + int(carry>0);
                result.number = to_string(digit_sum) + result.number;
                return result;
            }else{
                digit_sum = (first_number.number[delta]-'0') + (second_number.number[0]-'0') + int(carry>0);
                carry -= carry>0;
                if(digit_sum>9){
                    carry++;
                    digit_sum-=10;
                }
                //Keep adding remaining digits of the greater number to answer
                result.number = to_string(digit_sum) + result.number;
                int pointer = --delta;
                while (pointer>=0){
                    digit_sum = first_number.number[pointer]-'0' + int(carry>0);
                    carry -= carry>0;
                    if(digit_sum>9 && pointer>0){
                        digit_sum-=10;
                        carry++;
                    }
                    result.number = to_string(digit_sum) + result.number;
                    pointer--;
                }
                return result;
            }
        }
    }

    friend BigDecimalInt operator - (const BigDecimalInt& a, const BigDecimalInt& b){
        BigDecimalInt result;
        return result;
    }

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
     BigDecimalInt operator= (const BigDecimalInt& a)
     {
         this->number = a.number;
         this->num_sign = a.num_sign;
         this->sz = a.sz;
         return *this;
     }

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
        BigDecimalInt y = {"7060"};
        BigDecimalInt z = {"8050"};
        x = y;

        cout<<y+z<<endl;


        // cout << y << endl;             // the overloaded operator <<  printed -12 as -12
        // cout << y.getNumber() << endl; // holds value without signs  -12 is stored as 12 but printed as -12
        // cout << y.getSign() << endl;   // holds the sign + or -
        // cout << y.getSize() << endl;   // holds the size
    }
}
