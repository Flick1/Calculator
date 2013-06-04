#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include<curses.h>
#include<string>
#include<vector>

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

    //Simplifying and editting string for final operations
    void parentheses(std::vector<std::string>&);
    void spec_ops(std::vector<std::string>&);

    //Check validity of input
    bool chk_string(const std::string&);
    bool is_num(const std::vector<std::string>::iterator&);

};

#endif // SCREEN_H_INCLUDED
