#ifndef _INPUT_H_
#define _INPUT_H_
#include <iostream>

namespace input
{
    void get(int operands, double* input);
    size_t isNumerical_Selection(size_t&);
    double isOperand(double&);
    string isString_selection(string&);
}

#endif // _INPUT_H_
