#include "Output.h"

#include<curses.h>

void output::print(std::string msg)
{
    addstr(msg);
}

void output::print(std::stringstream& msg)
{
    addstr(msg.str());
}
