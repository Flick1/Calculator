#ifndef _INPUT_H_
#define _INPUT_H_
#include <iostream>

namespace input
{
    void get(int operands, double* input);
    size_t getNumerical_selection(size_t&);
    double getOperand(double&);
    std::string getString_selection(std::string&);
}

#endif // _INPUT_H_
