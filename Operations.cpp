#include <iostream>

double divide()
{
        double firstInput, secondInput;

        std::cin >> firstInput >> secondInput;

        firstInput /= secondInput;

        std::cout << firstInput << std::endl;

        return firstInput;
}
