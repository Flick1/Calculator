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
#include "Constants.h"

using std::vector;
using std::string;

int main()
{
    double input[4] = {0,0,0,0};
    double dataSelect[1];	//See comment on line 32
    Storage test;

    std::cout << "You're going to subtract: " << std::endl;

    input::get(2, input);
    operations::subtract(input[0], input[1]);

    std::cout << "Please select from the menu: " << std::endl << std::endl;

    test.printMenu();

    std::string enumSelect;
    MENUSELECT holdEnum; //Need an object in main in case a change to value is made on this object's reference(error handling)

    std::cin >> enumSelect; //For the moment as there isn't a string input function.
    holdEnum = test.selectMenu(enumSelect); //holdEnum gets the corresponding numerical value from enum input.

    input::get(1, dataSelect);

    std::cout << std::endl << test.getData(holdEnum, dataSelect[0]) << std::endl << std::endl;

    std::cout << "Subtracting with selected data." << std::endl;

    input::get(1, input);
    std::cout << operations::subtract(test.getData(holdEnum, dataSelect[0]), input[0]) << std::endl;

    test.printMenu();

return 0;
}

#endif
