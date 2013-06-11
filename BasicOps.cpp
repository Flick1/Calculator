#include "Operations.h"

double operations::subtract(double first,double second)
{
    return (first - second);
}

double operations::add(double first, double second)
{
    return (first + second);
}

double operations::multiply(double first, double second)
{
    return (first * second);
}

double operations::divide(double first, double second)
{
        if(second != 0)
                return first/second;
        else    throw 0x0BAD00;
}

double operations::Percentage(double number)
{
    return number / 100;
}

int operations::Exponent(double first, double second)
{
    while (second != 0)
    {
        first *= 10;
        --second;
    }

    return first;
}
