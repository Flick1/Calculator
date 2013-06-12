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
    /**
     * Believe it or not, people might confuse
     *    this function with changing a decimal
     *    to a percent instead of the opposite:
     *    changing a percent to a decimal. You
     *    could rectify this by changing the
     *    name to something like 
     *    PercenttoDecimal.
     * Also, you might not need this function.
     *    Take a look in Constants.h, which has
     *    a string literal percent function. It
     *    lets you write 34.5_Per where 34.5 is
     *    the percentage, but _Per--like f, L,
     *    u, and 0x--will return the correct
     *    value of 34.5, which in this case is 
     *    a double: 0.345.
    **/
double operations::Percentage(double number)
{
    return number / 100;
}
  /**
   * "Exponent" is a misleading name. It sounds like
   *    it could be a power function or maybe a
   *    logarithm that returns the exponent as the
   *    answer. One way to clarify is by renaming
   *    the parameters to what they are supposed to
   *    represent. Like pow(double base, double exponent)
   *    or log(double base, double input)
   * Also, from looking at your function, it seems it is
   *    equivalent to this:
   * int operations::Exponent(double sig, double exponent)
   * {
   *    return sig * pow(10,exponent);
   * }
   *    which is a method with valid use such as for
   *    writing scientific notation or classes and/or
   *    user-defined string literal that represent
   *    something similar to kilo-, milli-, etc.
   *    However, as I mentioned before, the name is
   *    very misleading. Someone could call this
   *    function expecting it to return pow(first,second)
   *    only to find a return larger than what they 
   *    expected.
  **/
int operations::Exponent(double first, double second)
{
    while (second != 0)
    {
        first *= 10;
        --second;
    }

    return first;
}
