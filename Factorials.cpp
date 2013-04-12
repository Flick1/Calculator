#include "Operations.h"
#include <iostream>

int factorial_int(double input){
  int whole = input;
  try{
    if((input - whole) != 0)   //Test if parameter is an integer
       throw "Error. Parameter not an integer. Use factorial_dec instead.";
    else
       return input*factorial_int(input-1);
  catch(const char* err){
      std::cout << err << std::endl;
  }
}

double factorial_dec(double input){
   std::cout << "Not available yet, sorry." << std::endl;
}
