#ifndef STORING_H_INCLUDED
#define STORING_H_INCLUDED

#include<iostream>
#include<vector>
#include<string>

class Storage
{
private:
    static std::vector<std::vector<double>> data;
    std::vector<std::string> names {"Subtraction", "Addition", "Divide", "Multiply"};
    
public:	//I read somewhere that having "const" in the prototypes is not neccessary
        //despite it being in the function definition. Some programmers do this
		//to hide that the parameter copies are const from other programmers (I have
		//no idea why). I suppose it is like the default value quirk where the function
		//defintion is void funct(int x, int y){...} but the prototype is void
		//funct(int=0, int=0);
    static void store(const int, const double);
    void printMenu();
    double getData(std::size_t, double);
};


#endif // STORING_H_INCLUDED
