#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "Handler.h"
#include "Storing.h"

//Initialize data to have 10 elements of vector types. The number should be the number of functions we have in main menu.
vector<vector<double>> Storage::data (10); 

//Stores results into the appropriate vector element based on menu selection.
void Storage::store(const int selectContain, const double inNum)
{
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
double Storage::getData(std::size_t row, double item)
{
    std::vector<double>::iterator srch;

    srch = std::find(data[row - 1].begin(), data[row - 1].end(), item);

    try
    {
        if (data[row - 1].empty()) //If the selected container(row) is empty, its' an invalid selection.
        {
            throw 42;
        }
    } catch (int err1) {
            std::cerr << "Error " << err1 << ", attempted to unlock secret of life. "
                         "Please reenter your menu selection." << std::endl;
        }

    try
    {
        if (srch == data[row - 1].end()) //If the selected data doesn't exist, its' an invalid selection.
        {
            throw 99;
        }
        else
            ++srch;

    } catch (int err2) {
        std::cerr << "Error " << err2 << " ocurred. Please enter an existing number from the list." << std::endl;
        }

    return *(srch - 1);
}

