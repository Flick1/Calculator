#ifndef _HANDLER_H_
#define HANDLER_H_
#include <sstream>
#include "Input.h"
#include "Output.h"
#include "Operations.h"

namespace handler
{
    bool menu(void);
    double input[4];
    std::ostream& ss;  //Why are you declaring a reference variable?

}


#endif // _HANDLER_H_
