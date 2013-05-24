#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include<curses.h>
#include<string>
#include<vector>

namespace Screen
{
    WINDOW *create_screen(WINDOW *win,  int height, int width, bool flag = FALSE, char* num = "a", bool hightlight = FALSE);
};

namespace String_Ops
{
    double convert(std::string &s);
    char* convert_print(double res);
    double parse(std::string &s);
    std::vector<std::string> calculate(std::vector<std::string> &, const std::string);
};

#endif // SCREEN_H_INCLUDED
