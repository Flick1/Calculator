#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include "Input.h"

using std::string;
using std::cin;
using std::istringstream;

void input::get(int operands, double* input)
{
    for (int i = 0; i < operands; i++)
    {
        string alttext;
        std::cin>>alttext;
        stringstream ss(alttext);
        ss>>*input;
        input++;
    }
}

//Whole num menu selection.
size_t input::getNumerical_selection(size_t &select)
{
    string num_select;
    getline(cin, num_select);

    istringstream iss(num_select);

    auto isPunct = std::find_if(num_select.begin(), num_select.end(), ispunct);
    auto isSpace = std::find_if(num_select.begin(), num_select.end(), isspace);
    auto isNum = std::find_if(num_select.begin(), num_select.end(), isalpha);

    try
    {
        if (isPunct == num_select.end() && isNum == num_select.end() && isSpace == num_select.end())
        {
            iss >> select;
        }
        else throw 1;
    }   catch (int err)
        {
            std::cerr << "Error " << err << ". Enter a whole number: ";
                return input::getNumerical_selection(select);
        }

    return select;
}

//Numerical input for operations
double input::getOperand (double &operand)
{
    string operand_str;
    getline(cin, operand_str);

    istringstream iss(operand_str);

    int cntNum = std::count_if(operand_str.begin(), operand_str.end(), isdigit);
    auto isSpace = std::find_if(operand_str.begin(), operand_str.end(), isspace);
    auto isChar = std::find_if(operand_str.begin(), operand_str.end(), isalpha);

    try
    {
        int convert = operand_str.size();
        if (cntNum >= (convert - 1) && isChar == operand_str.end() && isSpace == operand_str.end())
        {
            for (auto x = 0; x < convert; ++x)
            {
                if (ispunct(operand_str[x]))
                {
                    if (operand_str[x] != '.') { throw 2; }
                }
            }

            iss >> operand;
        }
        else throw 2;
    }   catch (int err)
        {
            std::cerr << "Error " << err << ". Enter a valid number: ";
            return getOperand(operand);
        }

    return operand;
}

//For enum selection. I'm aware it doesn't exactly support enum properly but just gonna post first. Might want to use
//set<> instead of enum.
string input::getString_selection(string &enumSelection)
{
    string str_selection;
    getline(cin, str_selection);

    istringstream iss(str_selection);

    auto isPunct = std::find_if(str_selection.begin(), str_selection.end(), ispunct);
    auto isSpace = std::find_if(str_selection.begin(), str_selection.end(), isspace);
    auto isString = std::find_if(str_selection.begin(), str_selection.end(), isdigit);

    try
    {
        if (isString == str_selection.end() && isPunct == str_selection.end() && isSpace == str_selection.end())
        {
            iss >> enumSelection;
        }
        else throw 3;
    }   catch (int err)
        {
            std::cerr << "Error " << err << ". Enter a valid word selection: ";
                return getString_selection(enumSelection);
        }

    return enumSelection;
}
