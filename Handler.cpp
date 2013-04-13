#include "Handler.h"

bool handler::menu(void)
{
    while(true)
    {
        output::print("test");
        input::get(1, input);

        switch (int(input[0]))
        {
        case 1:
            output::print("Enter the two numbers you want to add.");
            input::get(2, input);
            ss<<input[0]<<" + "<<input[1]<<" = "<<operations::add(input[0], input[1])<<"/n";
            output::print(ss);
            break;
        case 2:
            output::print("Enter the two numbers you want to subtract.");
            input::get(2, input);
            ss<<input[0]<<" - "<<input[1]<<" = "<<operations::subtract(input[0], input[1])<<"/n";
            output::print(ss);
            break;

        case 0:
            return false;
            break;

        }
    }
}
