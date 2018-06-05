#include <iostream> // for cout

#include "ArrayClass.h"

 

using namespace std;

 

// Function Prototype

void exceptionTest();

 

// Main function that is called when the program is executed

int main() {

      //arrayClassTest();

      exceptionTest();

 

      return 0;

}

 

void exceptionTest() {

      ArrayClass ac;

 

      // Insert 1 to 10 integers in ac

      int n = 10;

      for (int i = 0; i < n; ++i) {

             ac.insert(i + 1);

      }

 

      // Get and set values (which may throw errors)

      try {

             // "Accidentally" access the 11th element

             for (int i = 0; i <= ac.size(); ++i) {

                    ac.set(i,0);

             }

 

      }

      catch (std::out_of_range oor) {

             cout << oor.what() << endl;

      }

}