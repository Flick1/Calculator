#include "Operations.h"

int factorial_int(double input){
  int whole = input;
    if((input - whole) != 0)   //Test if parameter is an integer
       throw "Error. Parameter not an integer. Use factorial_dec instead.";
    else if(input == 0)   //Stop recursion to avoid negative values
      return 1;
    else
      return input*factorial_int(input-1);
}

double factorial_dec(double input){
   throw "Not available yet, sorry.";
}
