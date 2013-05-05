#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <curses.h>
#include <string>

namespace Screen
{
    WINDOW *create_screen(int startY, int startX, int height, int width, bool flag, chtype num);
};

namespace String_Ops
{
    double convert(std::string &s);
    char* convert_print(double res);
};


#endif // SCREEN_H_INCLUDED
