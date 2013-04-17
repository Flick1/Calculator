#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "Handler.h"
#include "Storing.h"

vector<vector<double>> Storage::data (10);

void Storage::store(const int selectContain, const double inNum)
{
    data.at(selectContain).push_back(inNum);
}


void Storage::printMenu()
{
    std::size_t namePos = 1;
    std::size_t cnt = 1;

    for (const auto outVec : data)
    {
        if(!outVec.empty())
        {
            std::cout << cnt << ". " << names[namePos - 1] << ": ";

            for (auto inVec : outVec)
            {
                std::cout << inVec << ", ";
            }
            std::cout << std::endl;
            ++cnt;
        }

        ++namePos;
    }
}

double Storage::getData(std::size_t row, double item)
{
    std::vector<double>::iterator srch;

    srch = std::find(data[row - 1].begin(), data[row - 1].end(), item);

    try
    {
        if (data[row - 1].empty())
        {
            throw 42;
        }
    } catch (int err1) {
            std::cerr << "Error " << err1 << ", attempted to unlock secret of life. "
                         "Please reenter your menu selection." << std::endl;
        }

    try
    {
        if (srch == data[row - 1].end())
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

