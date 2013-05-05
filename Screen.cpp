#include <curses.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include "Screen.h"

WINDOW *Screen::create_screen(int startY, int startX, int height, int width, bool flag, chtype num)
{
    WINDOW *win;

    win = newwin(height, width, startY, startX);
    box(win, 0, 0);

    if (flag == TRUE)
    {
        mvwaddch(win, (height - 1)/2, (width)/2, num);
    }

    wrefresh(win);
    return win;
}

double String_Ops::convert(std::string &s)
{
    std::istringstream iss(s);
    double ret;

    iss >> ret;
    s.erase();

    return ret;
}

char* String_Ops::convert_print(double res)
{
    int reserve = 10;
    char* ret;

    ret = (char *)malloc(reserve+1);

    sprintf(ret, "%f", res);

    return ret;
}
