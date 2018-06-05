#include "ArrayClass.h"

ArrayClass::ArrayClass(){
       arrSize = 2;
       arr = new int[arrSize];
       n = 0;
}

ArrayClass::~ArrayClass(){
       delete[] arr;
}

int ArrayClass::size(){
       return n;
}

void ArrayClass::insert(int value){

       if (n == arrSize) {

              arrSize *= 2;

              int* temp = arr;

              arr = new int[arrSize];

              for (int i = 0; i < n; i++) {

                     arr[i] = temp[i];

              }

              delete[] temp;

       }



       arr[n++] = value;

}



// Returns the sum of the contents of the array

// PRE:

// POST: Returns sum of the first n elements of a

int ArrayClass::sum()

{

       int result = 0;

       for (int i = 0; i < n; i++) {

              result += arr[i];

       }

       return result;

}



// Sets the value of the noted index

// PRE: 0 <= i < n

// POST arr[i] = value

// PARAM: i = index of element to be set, value = new value

void ArrayClass::set(int i, int value)

{
       if(i < 0 || i >= n) throw std::out_of_range("set(i,value) out of range");
       arr[i] = value;

}



// Gets the value at the noted index

// PRE: 0 <= i < n

// POST returns arr[i]

// PARAM: i = index of element to be returned

int ArrayClass::get(int i)

{

       return arr[i];

}