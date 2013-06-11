#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include<curses.h>
#include<string>
#include<vector>
#include<set>

namespace Screen
{
    WINDOW *create_screen(WINDOW *win,  int height, int width, bool flag = FALSE, char* num = "", bool hightlight = FALSE);
};

namespace String_Ops
{
    //Functions to print results
    double convert(std::string &s);
    char* convert_print(double res);

    //Calculations
    std::vector<std::string> tokenize (const std::string&);
    double parse(std::string &s);
    void binary_calculate(std::vector<std::string>&, const std::string);
    void unary_calculate(std::vector<std::string>&, const std::string);
    void misc_calculate(std::vector<std::string>&);

    //Simplifying and editting input for final operations
    void parentheses(std::vector<std::string>&);

    //Input management
    bool chk_string(const std::string&);
    bool is_num(const std::vector<std::string>::iterator&);
    void eraser(std::string&, std::string&, size_t&, bool&);

};

#endif // SCREEN_H_INCLUDED
