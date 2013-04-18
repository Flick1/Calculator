#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "Handler.h"
#include "Storing.h"	//<-- Might want to check the file names 

//Initialize data to have 10 elements of vector types. The number should be the number of functions we have in main menu.
vector<vector<double>> Storage::data (10); 

//Stores results into the appropriate vector element based on menu selection.
void Storage::store(const int selectContain, const double inNum)	//I get this error: "undefined reference to 'Storage::store(int,double)' "
                                                                    //Dunno where the error is from because the compiler only spotted the problem 
																	//in the virtual table
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
	/*
	try{
		if(data[row-1].empty())	throw 42;
		else if(srch == data[row-1].end())	throw 99;
	}catch(int err){
		switch(err){
			case 42:
				std::cerr << "Error " << err << ", attempted to unlock secret of life. "
                         << "Please reenter your menu selection.";
				break;
			case 99:
				std::cerr << "Error " << err << " ocurred. Please enter an existing number from the list.";
				break;
			default:
				std::cerr << "Unknown error " << err;
		}
		 std::cout << std::endl;
	}
	*/
    return *(srch - 1);
}


	//I am going to assume from the comment on line 8 that the Storage class is a way to select different functions...
	//What about:
	//   handler.h
	//enum handler::Menu_Option{
	//   Exit_Program,
	//   Add,
	//   Subtract,
	//   Multiply,
	//   ...
	//   Enum_Menu_End
	//};
	//class handler::Menu{
	//   public:
	//      void Execute_Choice();
	//      void Check_List(std::string);
	//      Menu();
	//   private:
	//      handler::Menu_Option User_Option;	//Value to store user's choice
	//      static const std::string Menu_Option_String[Enum_Menu_End];	//Store strings to match against user inputs
	//      static void (*functptr[Enum_Menu_End]);
	//};
	//   MenuOptions.cpp
	//void handler::Menu::Execute_Choice(){
	//   /*Call appropriate function pointer based on handler::Menu::User_Option...*/
	//}
	//void handler::Menu::Check_List(std::string parameter){
	//   /*Run parameter against handler::Menu::Menu_Option_String[]...*/
	//   /*Assign handler::Menu_Option value to handler::Menu::User_Option based on match
	//}
	//handler::Menu::Menu(){
	//   /*Initialize handler::Menu::Menu_Option_String[] and handler::Menu::(*functptr[])...*/
	//}
	//   main.cpp
	//#include <map>
	//...
	//int main(){
	//   std::string input;
	//   /*...Get user input...*/
	//   Check_List(input);
	//   Execute_Choice();
	//}
	//   This is just a suggestion as I'm not even sure how good of a solution the 
	//above might be. It makes use of function pointers and uses regular enums in a 
	//non-conventional way.
