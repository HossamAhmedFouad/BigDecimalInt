#pragma once
/*
    Name : Mohamed Waleed Mohamed
    ID  : 20210362
    Assignment : 1
    Problem : 8

*/
#include <iostream>


template <class T>

class Array {
private:
    T* smart_array;
    int current_size;

public:
// constructors
    Array();                    
    Array(int k);         
    Array(const Array*& a);   
// tracks size  
    int size();
// copies another array via deep copying
    Array& operator= (const Array& a);
// checks if k is valid index
    T & operator[](int k);
// destructor that frees memory allocated in heap
    ~Array();

};

