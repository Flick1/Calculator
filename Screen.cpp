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

std::vector<std::string> String_Ops::tokenize (const std::string&s)
{
    std::vector<std::string> tokenize;
    std::string token;

    std::istringstream iss(s);

    while (iss >> token)
    {
        tokenize.push_back(token);
    }

    return tokenize;
}

double String_Ops::parse(std::string& s)
{
    std::vector<std::string> token = tokenize(s);

    while (token.size() > 1)
    {
        String_Ops::parentheses(token);
        String_Ops::spec_ops(token);
        String_Ops::unary_calculate(token, "cos");
        String_Ops::unary_calculate(token, "sin");
        String_Ops::unary_calculate(token, "tan");
        String_Ops::unary_calculate(token, "log");
        String_Ops::unary_calculate(token, "s.r");
        String_Ops::binary_calculate(token, "*");
        String_Ops::binary_calculate(token, "/");
        String_Ops::binary_calculate(token, "-");
        String_Ops::binary_calculate(token, "+");
    }

    auto operand = token.begin();
    double ret = String_Ops::convert(*(operand));

    return ret;
}

void String_Ops::binary_calculate(std::vector<std::string> &str_expression, const std::string str_operator)
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

void String_Ops::unary_calculate(std::vector<std::string> &str_expression, const std::string str_operator)
{
    for (auto iter = str_expression.begin(); iter != str_expression.end(); ++iter)
    {
        if (*iter == str_operator && String_Ops::is_num(iter + 1))
        {
            double operand = String_Ops::convert(*(iter + 1));
            double result = 0;

            if (str_operator == "cos")
                result = operations::Cosine(operand);
            if (str_operator == "sin")
                result = operations::Sine(operand);
            if (str_operator == "tan")
                result = operations::Tangent(operand);
            if (str_operator == "log")
                result = operations::Logarithm_Base10(operand);
            if (str_operator == "s.r")
                { /*Missing*/ }

            std::string restore;

            std::ostringstream oss;

            oss << result;
            restore = oss.str();

            auto new_pos = str_expression.erase(iter, iter + 2);
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
                std::set<std::string> basic_ops { "*", "/", "+", "-" };
                std::set<std::string> special_ops { "cos", "sin", "tan", "log", "s.r" };

                String_Ops::unary_calculate(paren_simp, "cos");
                String_Ops::unary_calculate(paren_simp, "tan");
                String_Ops::unary_calculate(paren_simp, "sin");
                String_Ops::unary_calculate(paren_simp, "log");
                String_Ops::unary_calculate(paren_simp, "s.r");
                String_Ops::binary_calculate(paren_simp, "*");
                String_Ops::binary_calculate(paren_simp, "/");
                String_Ops::binary_calculate(paren_simp, "-");
                String_Ops::binary_calculate(paren_simp, "+");

                //Processing final result of simplification
                if (paren_simp.size() == 1)
                {
                    //Checking open bracket
                    if (beginParen != str_expression.begin()) //Check that open bracket is NOT the initial element
                    {
                        if (basic_ops.find(*(beginParen - 1)) == basic_ops.end() &&
                            *(beginParen - 1) != "(" &&
                            special_ops.find(*(beginParen - 1)) == special_ops.end())  //Check element before open bracket is a number
                        {
                            str_expression.insert(beginParen, "*");
                        }
                    }

                    //Checking close bracket
                    if (endParen + 1 != str_expression.end()) //Close bracket is NOT the last element.
                    {
                        if (basic_ops.find(*(endParen + 1)) == basic_ops.end() &&
                            *(endParen + 1) != ")" || *(endParen + 1) == "(" ||
                            special_ops.find(*(endParen + 1)) != special_ops.end()) //Check element after close bracket if its a number, closed bracket, or spec ops.
                        {
                            endParen = str_expression.insert(endParen + 1, "*") - 1;
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

void String_Ops::spec_ops(std::vector<std::string> &token)
{
    std::set<std::string> basic_ops { "*", "/", "+", "-" };
    std::set<std::string> special_ops { "cos", "sin", "tan", "log", "s.r" };

    for (auto iter = token.begin(); iter != token.end(); ++iter)
    {
        if (special_ops.find(*iter) != special_ops.end() &&
            iter != token.begin())
        {
            //If left-hand side is a number, add *
            if (iter != token.begin() && String_Ops::is_num(iter))
            {
                token.insert(iter, "*");
                iter = token.begin();
            }
        }
    }
}


bool String_Ops::chk_string(const std::string &s)
{
    std::vector<std::string> token = tokenize(s);

    std::set<std::string> basic_ops { "+", "-", "*", "/" };
    std::set<std::string> special_ops { "cos", "sin", "tan", "log", "s.r" };

    if (basic_ops.find(*token.begin()) != basic_ops.end() ||
        basic_ops.find(*(token.end() - 1)) != basic_ops.end() &&
        special_ops.find(*(token.end() - 1)) != special_ops.end())
        {
            return false;
        }

    for (auto iter = token.begin(); iter != token.end(); ++iter)
    {
        //Determining validity of basic operations
        if (basic_ops.find(*iter) != basic_ops.end())
        {
            //Left-hand side
            if (basic_ops.find(*(iter - 1)) != basic_ops.end() ||
                special_ops.find(*(iter - 1)) != special_ops.end()) { return false; }

            //Right-hand side
            if (basic_ops.find(*(iter + 1)) != basic_ops.end() ||
                *iter == ")")                                       { return false; }
        }

        //Determining validity of parentheses
        if (*iter == "(")
        {
            if (*(iter + 1) == ")" ||
                basic_ops.find(*(iter + 1)) != basic_ops.end()) return false;

            //Something about misc operations.
        }

        //All posibilities of special ops are valid
    }
    return true;
}

bool String_Ops::is_num(const std::vector<std::string>::iterator &iter)
{
    std::set<std::string> basic_ops { "+", "-", "*", "/" };
    std::set<std::string> special_ops { "cos", "sin", "tan", "log", "s.r" };

    if (basic_ops.find(*iter) == basic_ops.end() &&
        special_ops.find(*iter) == special_ops.end() &&
        *iter != "(" && *iter != ")")
    {
        return true;
    }
    else
        return false;
}

