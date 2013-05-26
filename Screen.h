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
    double convert(std::string &s);
    char* convert_print(double res);
    double parse(std::string &s);
    void calculate(std::vector<std::string> &, const std::string);
    void parentheses(std::vector<std::string>&);

    /*void chk_string(const std::string&); */
};

#endif // SCREEN_H_INCLUDED
