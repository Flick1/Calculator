#include "Output.h"

void output::print(std::string msg)
{
    std::cout<<msg;
}

void output::print(std::stringstream& msg)
{
    std::cout<<msg.str();
}
