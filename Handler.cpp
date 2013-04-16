#include "Handler.h"
#include "Input.h"
#include "Output.h"
#include "Operations.h"

bool handler::menu(void)
{
    double input[4] = {0,0,0,0};
    std::stringstream ss;

    while(true)
    {
        output::print("Main menu goes here, 1 is add, 2 is subtract for now\n");
        input::get(1, input);
				//You have the option of "'using namespace operations;' and 'using operations::[functionname];'"
        switch (int(input[0]))
        {
        case 1:
            output::print("Enter the two numbers you want to add.");
            input::get(2, input);
            ss<<input[0]<<" + "<<input[1]<<" = "<<operations::add(input[0], input[1])<<"\n";
            output::print(ss);
            break;
        case 2:
            output::print("Enter the two numbers you want to subtract.\n");
            input::get(2, input);
            ss<<input[0]<<" - "<<input[1]<<" = "<<operations::subtract(input[0], input[1])<<"\n";
            output::print(ss);
            break;

        case 0:
            return false;
            break;

        }
    }
}
