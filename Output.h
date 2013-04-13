#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <iostream>
#include <sstream>

namespace output
{
    void print(std::string msg);
    void print(std::stringstream& msg);
}

#endif // _OUTPUT_H_
