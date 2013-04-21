#ifndef STORING_H_INCLUDED
#define STORING_H_INCLUDED

#include<iostream>
#include<vector>
#include<string>

enum MENUSELECT //Not sure if this is the right place to put, but I tried putting in handler.h and its' somehow not
		//declared on line 34 and 35.
{
    DEFAULT,
    Subtraction,
    Addition,
    Divide,
    Multiply,
};

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
		
	//Guess its' to avoid people stealing their stuff. I'll just leave it there for consistency(hurh hurh) sake.
    static void store(const std::size_t, const double);
    void printMenu();
    double getData(MENUSELECT&, double&);
    MENUSELECT selectMenu(std::string&);
};


#endif // STORING_H_INCLUDED
