#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "Handler.h"
#include "Storage.h"

using std::vector;

//Initialize data to have 10 elements of vector types. The number should be the number of functions we have in main menu.
vector<vector<double>> Storage::data (10); 

//Stores results into the appropriate vector element based on menu selection.
void Storage::store(const std::size_t selectContain, const double inNum){
    data.at(selectContain).push_back(inNum);
}


MENUSELECT Storage::selectMenu(std::string &s) //Convert string input to integer used in menu selection.
{
    MENUSELECT sm = DEFAULT;

    if (s == "Subtraction" || s == "subtraction") { sm = Subtraction; }
    if (s == "Addition" || s == "addition") { sm = Addition; }
    if (s == "Divide" || s == "divide") { sm = Divide; }
    if (s == "Multiply" || s == "multiply") { sm = Multiply; }

    return sm;
}

//Displays stored data along with the appropriate name.
void Storage::printMenu()
{
    std::size_t namePos = 1;
    std::size_t cnt = 0;

    for (const auto outVec : data)
    {
        if(!outVec.empty())
        {
            std::cout << names[namePos - 1] << ": ";

            for (auto inVec : outVec)
            {
                std::cout << "(" << cnt << ")" << inVec << " ";
                ++cnt;
            }
            std::cout << std::endl;
        }
        ++namePos;
    }
}

//Request the selected container (row) and the specific number.
double Storage::getData(MENUSELECT &row, double &item) //item should be type size_t now (I guess), but input function
						       //can only support double types.
{
    try
    {
		if(data[row - 1].empty())	throw 42;
		else if(item >= data[row - 1].size())	throw 99;

	}catch(int err){

		switch(err)
		{
			case 42:
			    {
			        std::cerr << "Error " << err << ", attempted to unlock secret of life. "
                         << "Please reenter your menu selection.";

                    std::string enumSelect; //Makeshift error handler until something better comes around.
                    std::cin >> enumSelect; //No input function that supports strings.
                    row = Storage::selectMenu(enumSelect);

                    return getData(row, item);

			    }
			case 99:
			    {
			        std::cerr << "Error " << err << " ocurred. Please enter an existing number from the list.";

			        std::cin >> item; //Makeshift error handler. Current input function requires creating
			        		  //a new array. Input from that doesn't translate back to main().

			        return getData(row, item);
			    }
			default:
				std::cerr << "Unknown error " << err;
		}
		 std::cout << std::endl;
	}

    return data[row - 1][item];
}
