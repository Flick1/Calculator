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
    
public:
    static void store(const int, const double);
    void printMenu();
    double getData(std::size_t, double);
};


#endif // STORING_H_INCLUDED
