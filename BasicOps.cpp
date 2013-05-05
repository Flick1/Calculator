#include "Operations.h"

double operations::subtract(double first,double second)
{
    double sum = first - second;

    return sum;

}

double operations::add(double a, double b)
{
    return a+b;
}

double operations::multiply(double firstnumber, double secondnumber){return firstnumber*secondnumber;}


double operations::divide(double firstInput, double secondInput)
{
        if(secondInput != 0)
                return firstInput/secondInput;
        else    throw 0x0BAD00;
}
