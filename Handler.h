#ifndef _HANDLER_H_
#define HANDLER_H_
#include <sstream>
#include "Input.h"
#include "Output.h"
#include "Operations.h"

namespace handler
{
    bool menu(void);
<<<<<<< HEAD
    extern double input[4];
    extern std::stringstream ss;
=======
    double input[4];
    std::ostream& ss;  //Why are you declaring a reference variable?
>>>>>>> 30630d90dd0125333cc757aaac5813fb62a9399c

}


#endif // _HANDLER_H_
