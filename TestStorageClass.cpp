//Requires the following header includes, Subtract.cpp, Storage.cpp, and Input.cpp.
//Lacks proper error handling. Been trying to figure out a way to deal with it (ie. user selecting containers that
//don't exist) but I can't seem to find a decent source that teaches about error handling.
//To get data from stored menu, selection starts at one. Then input the exact number you want to get.

#ifdef DEBUG_STORAGECLASS
	//Encapsulate test file
#include <vector>
#include <string>
#include <iostream>
#include "Handler.h"
#include "Operations.h"
#include "Storage.h"

using std::vector;
using std::string;

int main()
{
    double input[4] = {0,0,0,0};
    double select[2];	//See comment on line 32
    Storage test;

    std::cout << "You're going to subtract: " << std::endl;

    input::get(2, input);
    operations::subtract(input[0], input[1]);

    std::cout << "Please select from the menu: " << std::endl << std::endl;

    test.printMenu();

    input::get(2, select);	//select is declared as an array of size 1...
    				//somehow it still worked in codeblocks =/, changed it.
    				//   That is not surprising... This data is stored on a stack, which means 
    				//the memory addresses and what they hold lie next to each other. You grabbed
    				//something that you weren't supposed to grab by going out of bounds. I have done this before
    				//and was able to see the consequences when I declared two arrays side-by-side and created a
    				//function that was supposed to work with the first but accidently messed with the second.
    std::cout << test.getData(select[0], select[1]) << std::endl;

    std::cout << "Subtracting with selected data." << std::endl;

    input::get(1, input);
    std::cout << operations::subtract(test.getData(select[0], select[1]), input[0]) << std::endl;

    test.printMenu();

return 0;
}

#endif
