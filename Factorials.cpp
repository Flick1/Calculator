#include "Operations.h"
#include <cmath>

int operations::factorial_int(double input){
  int whole = input;
    if((input - whole) != 0.0)   //Test if parameter is an integer
       throw "Error. Parameter not an integer. Use factorial_dec instead.";
    else if(input == 0)   //Stop recursion to avoid negative values
      return 1;
    else
      return input*operations::factorial_int(input-1);
}

double operations::factorial_dec(double input){
  int limit = 0;
  double summation = 0;
  while(limit != ~0){  //Gamma function, sum e^-limit * limit^(input-1) from 0 to maximum integer value minus 1
     summation += exp(limit*(-1))*pow(limit, input-1);
     limit++;
  }
  return summation;
}
