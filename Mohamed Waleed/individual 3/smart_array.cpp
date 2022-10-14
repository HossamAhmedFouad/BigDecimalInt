/*
    Name : Mohamed Waleed Mohamed
    ID  : 20210362
    Assignment : 1
    Problem : 8

*/
#include <iostream>
#include "smart_array.hpp"
using namespace std;

template<typename T>
Array<T>::Array(){
    smart_array = new T[1];
    current_size = 1;
}

template<typename T>
Array<T>::Array(int k){
    smart_array = new T[k];
    current_size = k;
}

template<typename T>
Array<T>::Array(const Array*& a)
{
    current_size = a->current_size;
    smart_array = new T[current_size];
    for (int i = 0; i < a->current_size ; i++)
        smart_array[i] = a->smart_array[i];       
}

template<typename T>
int Array<T>::size(){return current_size;}

template<typename T>
Array<T>& Array<T>::operator= (const Array<T>& a){
    this->current_size = a.current_size;
    delete [] this->smart_array;
    this->smart_array = new int[a.current_size];
    for (int i = 0; i < a.current_size; i++)
        this->smart_array[i] = a.smart_array[i];
    
    return *this;
}

template<typename T>
T & Array<T>::operator[](int k){
    if (current_size <= k){
        cout << "index: " << k << " is out of boundary." << endl;
        return smart_array[99999];
    }
    else{
        return smart_array[k];
    }
}

template<typename T>
Array<T> :: ~Array(){
        delete[] smart_array;
    }
