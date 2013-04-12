#include <iostream>
#include "Operations.h"

double operations::divide()
{
        double firstInput, secondInput;

        std::cout << "Division - Please enter the first number: ";
        std::cin >> firstInput;
        std::cout << "Division - Please enter the second number: ";
        std::cin >> secondInput;

        firstInput /= secondInput;

        return firstInput;
}
