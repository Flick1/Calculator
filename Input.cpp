#include "Input.h"

void input::get(int operands, double* input)
{
    for (int i = 0; i < operands; i++)
    {
        std::cin>>*input;
        input++;
    }
}
