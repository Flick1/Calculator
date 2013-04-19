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

//Displays stored data along with the appropriate name.
void Storage::printMenu()
{
    std::size_t namePos = 1; //To seek out the appropriate name of the operation from a vector of const names.
    std::size_t cnt = 1; //Selection numbering to aid user in selecting available containers.

    for (const auto outVec : data)
    {
        if(!outVec.empty()) //Searches vector<vector<double>> data and only processes if it isn't empty.
        {
            std::cout << cnt << ". " << names[namePos - 1] << ": "; //Operation name and location in data.

            for (auto inVec : outVec)
            {
                std::cout << inVec << ", "; //Print out stored data within vector element.
            }
            std::cout << std::endl;           
        }
        ++cnt;
        ++namePos;
    }
}

//Request the selected container (row) and the specific number.
double Storage::getData(const std::size_t row, const double item)
{
    std::vector<double>::iterator srch;

    srch = std::find(data[row - 1].begin(), data[row - 1].end(), item);

    try
    {
		if(data[row-1].empty())	throw 42;
		else if(srch == data[row-1].end()) throw 99;
		else ++srch;
	}catch(int err){

		switch(err)
		{
			case 42: //If selected container is empty.
				std::cerr << "Error " << err << ", attempted to unlock secret of life. "
                         		  << "Please reenter your menu selection.";
				break;
			case 99: //If selected data within container doesn't exist.
				std::cerr << "Error " << err << " ocurred. Please enter an existing number from the list.";
				break;
			default:
				std::cerr << "Unknown error " << err;
		}
		std::cout << std::endl;
	}

    return *(srch - 1);
}