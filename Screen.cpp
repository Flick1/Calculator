#include<curses.h>
#include<cstring>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<sstream>
#include<set>
#include<algorithm>

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

    while (tokenize.size() > 1)
    {
        String_Ops::parentheses(tokenize);
        String_Ops::calculate(tokenize, "*");
        String_Ops::calculate(tokenize, "/");
        String_Ops::calculate(tokenize, "-");
        String_Ops::calculate(tokenize, "+");
    }

    auto operand = tokenize.begin();
    double ret = String_Ops::convert(*(operand));

    return ret;
}

void String_Ops::calculate(std::vector<std::string> &str_expression, const std::string str_operator)
{
    for (auto iter = str_expression.begin(); iter != str_expression.end(); ++iter)
    {
        if (*iter == str_operator)
        {
            double first = String_Ops::convert(*(iter - 1));
            double second = String_Ops::convert(*(iter + 1));

            double result = 0;

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
}

void String_Ops::parentheses(std::vector<std::string> &str_expression)
{
    bool flag = false;
    auto beginParen = str_expression.begin();
    auto endParen = str_expression.begin();

    for (auto iter = str_expression.begin(); iter != str_expression.end(); ++iter)
    {
        if (*iter == "(")
        {
            beginParen = iter;
            flag = false;
        }
        if (*iter == ")")
        {
            endParen = iter;
            flag = true;
        }

        if (flag == true)
        {
            size_t paren_size = endParen - (beginParen + 1);

            std::vector<std::string> paren_simp ( paren_size );
            copy(beginParen + 1, endParen, paren_simp.begin()); //paren_simp gets expression without brackets

            do
            {
                std::set<std::string> operatorSet { "*", "/", "+", "-" };

                String_Ops::calculate(paren_simp, "*");
                String_Ops::calculate(paren_simp, "/");
                String_Ops::calculate(paren_simp, "-");
                String_Ops::calculate(paren_simp, "+");

                //Processing final result of simplification
                if (paren_simp.size() == 1)
                {
                    //Checking open bracket
                    if (beginParen != str_expression.begin()) //Check that open bracket is NOT the initial element

                        if (operatorSet.find(*(beginParen - 1)) == operatorSet.end() &&
                            *(beginParen - 1) != "(" )                                  //Check element before open bracket is a number
                        {
                            str_expression.insert(beginParen, "*");
                        }

                    //Checking close bracket
                    if (endParen + 1 != str_expression.end()) //Close bracket is NOT the last element.
                    {
                        if (operatorSet.find(*(endParen + 1)) == operatorSet.end() &&
                            *(endParen + 1) != ")" || *(endParen + 1) == "(" )        //Check element after close bracket is a number
                        {
                            endParen = str_expression.insert(endParen + 1, "*") - 1;
                        }
                        else
                        {
                            /*Note to self: Special operators (cos, sin, tan, "(", etc.) needs special consideration here.*/
                        }
                    }

                    auto newpos = str_expression.erase(beginParen, endParen + 1);
                    str_expression.insert(newpos, *paren_simp.begin());
                    iter = str_expression.begin();
                    flag = false;
                }
                // End of process

            } while (paren_simp.size() > 1);
        }
    }
}


/*
void chk_string(const std::string &str)
{
    std::set<char> function_list { '+', '*', '-', '/' };
}
*/
