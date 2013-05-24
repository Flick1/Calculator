#include<curses.h>
#include<string.h>
#include<sstream>
#include<vector>
#include<stdlib.h>
#include<sstream>
#include<set>
#include<algorithm>

#include<iostream>

#include "Screen.h"
#include "Operations.h"

WINDOW *Screen::create_screen(WINDOW *win, int y, int x, bool flag, char* num, bool hightlight)
{
    box(win, 0, 0);

    if (flag == TRUE)
    {
        mvwprintw(win, x, y, num);
    }

    if (hightlight == TRUE)
    {
        wattron(win, A_REVERSE);
        mvwprintw(win, y, x, num);
        wattroff(win, A_REVERSE);
    }

    wrefresh(win);
    return win;
}

double String_Ops::convert(std::string &s)
{
    std::istringstream iss(s);
    double ret;

    iss >> ret;

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


double String_Ops::parse(std::string& s)
{
    std::vector<std::string> tokenize;
    std::string token;

    std::istringstream iss(s);

    while (iss >> token)
    {
        tokenize.push_back(token);
    }

    while (tokenize.size() > 3)
    {
        String_Ops::calculate(tokenize, "*");
        String_Ops::calculate(tokenize, "/");
        String_Ops::calculate(tokenize, "-");
        String_Ops::calculate(tokenize, "+");
    }

    auto operand = tokenize.begin();
    double first = String_Ops::convert(*(operand));
    double second = String_Ops::convert(*(operand + 2));

    return operations::add(first, second);
}

std::vector<std::string> String_Ops::calculate(std::vector<std::string> &str_expression, const std::string str_operator)
{

    for (auto iter = str_expression.begin(); iter != str_expression.end(); ++iter)
    {
        if (*iter == str_operator)
        {
            double first = String_Ops::convert(*(iter - 1));
            double second = String_Ops::convert(*(iter + 1));

            double result;

            if (str_operator == "*")
                result = operations::multiply(first, second);
            if (str_operator == "/")
                result = operations::divide(first, second);
            if (str_operator == "+")
                result = operations::add(first, second);
            if (str_operator == "-")
                result = operations::subtract(first, second);

            std::string restore;

            std::ostringstream oss;

            oss << result;
            restore = oss.str();

            auto new_pos = str_expression.erase(iter - 1, iter + 2);
            str_expression.insert(new_pos, restore);

            iter = str_expression.begin();
        }
    }

    return str_expression;
}

