#include <iostream>
#include "Operations.h"

double operations::divide(double firstInput, double secondInput)
{
        if(secondInput != 0)
                return firstInput/secondInput;
        else    throw 0x0BAD00;
}
