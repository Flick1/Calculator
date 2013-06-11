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

std::set<std::string> basic_ops { "+", "-", "x", "/" };
std::set<std::string> special_ops { "cos", "sin", "tan", "log", "srt", "ln" };

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
        String_Ops::misc_calculate(token);
        String_Ops::binary_calculate(token, "E");
        String_Ops::unary_calculate(token, "cos");
        String_Ops::unary_calculate(token, "sin");
        String_Ops::unary_calculate(token, "tan");
        String_Ops::unary_calculate(token, "log");
        String_Ops::unary_calculate(token, "ln");
        String_Ops::unary_calculate(token, "srt");
        String_Ops::binary_calculate(token, "x");
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
    auto begIter = str_expression.begin();
    auto endIter = str_expression.end();

    for (auto begIter = str_expression.begin(); begIter != endIter; ++begIter)
    {
        if (*begIter == str_operator)
        {
            double first = String_Ops::convert(*(begIter - 1));
            double second = String_Ops::convert(*(begIter + 1));

            double result = 0;

            if (str_operator == "x")
                result = operations::multiply(first, second);
            if (str_operator == "/")
                result = operations::divide(first, second);
            if (str_operator == "+")
                result = operations::add(first, second);
            if (str_operator == "-")
                result = operations::subtract(first, second);
            if (str_operator == "E")
                result = operations::Exponent(first, second);

            std::string restore;
            std::ostringstream oss;

            oss << result;
            restore = oss.str();

            auto new_pos = str_expression.erase(begIter - 1, begIter + 2);
            str_expression.insert(new_pos, restore);

            begIter = str_expression.begin();
            endIter = str_expression.end();
        }
    }
}

void String_Ops::unary_calculate(std::vector<std::string> &str_expression, const std::string str_operator)
{
    auto begIter = str_expression.begin();
    auto endIter = str_expression.end();

    for (auto begIter = str_expression.begin(); begIter != endIter; ++begIter)
    {
        if (*begIter == str_operator && String_Ops::is_num(begIter + 1))
        {
            double operand = String_Ops::convert(*(begIter + 1));
            double result = 0;

            if (str_operator == "cos")
                result = operations::Cosine(operand);
            if (str_operator == "sin")
                result = operations::Sine(operand);
            if (str_operator == "tan")
                result = operations::Tangent(operand);
            if (str_operator == "log")
                result = operations::Logarithm_Base10(operand);
            if (str_operator == "srt")
                result = operations::Square_Root(operand);
            if (str_operator == "ln")
                result = operations::Logarithm_Natural(operand);

            std::string restore;
            std::ostringstream oss;

            oss << result;
            restore = oss.str();

            auto new_pos = str_expression.erase(begIter, begIter + 2);
            str_expression.insert(new_pos, restore);

            begIter = str_expression.begin();
            endIter = str_expression.end();
        }
    }
}

void String_Ops::misc_calculate(std::vector<std::string> &str_expression)
{
    auto begIter = str_expression.begin();
    auto endIter = str_expression.end();

    for (; begIter != endIter; ++begIter)
    {
        if (*begIter == "!" || *begIter == "per")
        {
            double result = 0;

            if (begIter != str_expression.begin())
                if (basic_ops.find(*(begIter - 1)) != basic_ops.end()) //Determine if lhs is a basic operator
                {
                    begIter = str_expression.erase(begIter - 1, begIter);
                    endIter = str_expression.end();
                }

            //right-hand side
            if (begIter != str_expression.end() - 1)
                if (String_Ops::is_num(begIter + 1))
                {
                    begIter = str_expression.insert(begIter + 1, "x") - 1;
                    endIter = str_expression.end();
                }

            //Add default 0
            if (begIter == str_expression.begin())
            {
                begIter = str_expression.insert(begIter, "0") + 1;
                endIter = str_expression.end();
            }

            double operand = String_Ops::convert(*(begIter - 1));

            if (*begIter == "!")
                result = operations::factorial_int(operand);
            if (*begIter == "per")
                result = operations::Percentage(operand);

            std::string restore;
            std::ostringstream oss;

            oss << result;
            restore = oss.str();

            auto new_pos = str_expression.erase(begIter - 1, begIter + 1);
            str_expression.insert(new_pos, restore);

            begIter = str_expression.begin();
            endIter = str_expression.end();
        }
    }
}

void String_Ops::parentheses(std::vector<std::string> &str_expression)
{
    bool flag = false;
    auto beginParen = str_expression.begin();
    auto endParen = str_expression.begin();

    auto begIter = str_expression.end();
    auto endIter = str_expression.end();

    for (auto begIter = str_expression.begin(); begIter != endIter; ++begIter)
    {
        if (*begIter == "(")
        {
            beginParen = begIter;
            flag = false;
        }
        if (*begIter == ")")
        {
            endParen = begIter;
            flag = true;
        }

        if (flag == true)
        {
            size_t paren_size = endParen - (beginParen + 1);

            std::vector<std::string> paren_simp ( paren_size );
            copy(beginParen + 1, endParen, paren_simp.begin()); //paren_simp gets expression without brackets

            do
            {
                String_Ops::misc_calculate(paren_simp);
                String_Ops::unary_calculate(paren_simp, "cos");
                String_Ops::unary_calculate(paren_simp, "tan");
                String_Ops::unary_calculate(paren_simp, "sin");
                String_Ops::unary_calculate(paren_simp, "log");
                String_Ops::unary_calculate(paren_simp, "srt");
                String_Ops::binary_calculate(paren_simp, "x");
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
                            beginParen = str_expression.insert(beginParen, "x") + 1;
                            endParen = (beginParen + (paren_size + 1));
                        }
                    }

                    //Checking close bracket
                    if (endParen + 1 != str_expression.end()) //Close bracket is NOT the last element.
                    {
                        if (basic_ops.find(*(endParen + 1)) == basic_ops.end() &&
                            *(endParen + 1) != ")" || *(endParen + 1) == "(" ||
                            special_ops.find(*(endParen + 1)) != special_ops.end()) //Check element after close bracket if its a number, closed bracket, or spec ops.
                        {
                            endParen = str_expression.insert(endParen + 1, "x") - 1;
                            beginParen = (endParen - (paren_size + 1));
                        }
                    }

                    auto newpos = str_expression.erase(beginParen, endParen + 1);
                    str_expression.insert(newpos, *paren_simp.begin());
                    begIter = str_expression.begin();
                    endIter = str_expression.end();
                    flag = false;
                }
                // End of process

            } while (paren_simp.size() > 1);
        }
    }
}

bool String_Ops::chk_string(const std::string &s)
{
    std::vector<std::string> token = tokenize(s);

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
            //Check if basic operation is at the beginning or end
            if (iter == token.begin() || iter == token.end() - 1)   { return false;}

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
                basic_ops.find(*(iter + 1)) != basic_ops.end())     { return false; }
        }

        if (*iter == "E")
        {
            //Check this first to ensure we are not accessing nonexisting elements
            if (iter == token.begin() || iter == token.end() - 1)       { return false; }
            if (!(String_Ops::is_num(iter - 1)) &&
                !(String_Ops::is_num(iter + 1)))                    { return false; }

            //Determine that lhs and rhs are not whole numbers
            if (find((iter - 1)->begin(), (iter - 1)->end(), '.') != (iter - 1)->end() ||
                find((iter + 1)->begin(), (iter + 1)->end(), '.') != (iter + 1)->end())
            {
                return false;
            }
        }

        //All posibilities of misc operators are valid
        //All posibilities of special ops are valid
    }
    return true;
}

bool String_Ops::is_num(const std::vector<std::string>::iterator &iter)
{
    std::set<std::string> misc { "per", "!", "3.14159265359", "2.71828182846", "e", "E" };

    if (basic_ops.find(*iter) == basic_ops.end() &&
        special_ops.find(*iter) == special_ops.end() &&
        misc.find(*iter) == misc.end() &&
        *iter != "(" && *iter != ")")
    {
        return true;
    }
    else
        return false;
}

void String_Ops::eraser(std::string &currBuffer, std::string &currDisplay, size_t &parenCnt, bool &dot)
{
    auto token = String_Ops::tokenize(currBuffer);
    auto lastElement = token.end() - 1;

    size_t bufferSize = 0;

    currBuffer.erase();

    //To avoid accessing elements that don't exist or committing unwanted expressions
    if (token.size() > 1 && !(String_Ops::is_num(lastElement)) && *lastElement != "per")
    {
        //Determine if last element is a special ops
        if (*lastElement == "(" &&
            special_ops.find(*(lastElement - 1)) != special_ops.end())
        {
            currDisplay.erase(currDisplay.end() - ((lastElement - 1)->size() + 1), currDisplay.end());
            token.erase(lastElement - 2, token.end());

            for (auto srch : token)
            {
                currBuffer.insert(bufferSize, " " + srch + " ");
                bufferSize += (srch.size() + 2);
            }

            parenCnt -= 2;
        }

        //Determine if last element is pi or euler natural
        else if (*lastElement == ")" &&
                *(lastElement - 1) == "3.14159265359" || *(lastElement - 1) == "2.71828182846")
        {
            if (*(lastElement - 1) == "3.14159265359")
                currDisplay.erase(currDisplay.end() - 2, currDisplay.end());
            if (*(lastElement - 1) == "2.71828182846")
                currDisplay.erase(currDisplay.end() - 1, currDisplay.end());

            token.erase(lastElement - 2, token.end());

            for (auto srch : token)
            {
                currBuffer.insert(bufferSize, " " + srch + " ");
                bufferSize += (srch.size() + 2);
            }
        }
    }

    //Determine if percentage
    if (*lastElement == "per")
    {
        currDisplay.erase(currDisplay.end() - 3, currDisplay.end());
        token.erase(lastElement, token.end());

        for (auto srch : token)
        {
            currBuffer.insert(bufferSize, " " + srch + " ");
            bufferSize += (srch.size() + 2);
        }
    }

    //Numeric or operations represented by a singular char input
    //To avoid accessing elements that don't exist or committing unwanted expressions
    if (String_Ops::is_num(lastElement) || lastElement->size() == 1)
    {
        currDisplay.erase(currDisplay.end() - 1, currDisplay.end());

        if (String_Ops::is_num(lastElement))
        {
            lastElement->erase(lastElement->end() - 1, lastElement->end());
        }
        else
            token.erase(lastElement, token.end());

        for (auto iter = token.begin(); iter != token.end(); ++iter)
        {
            if (String_Ops::is_num(iter))
            {
                currBuffer.insert(bufferSize, *iter);
                bufferSize += iter->size();
            }
            else
            {
                currBuffer.insert(bufferSize, " " + *iter + " ");
                bufferSize += (iter->size() + 2);
            }
        }
    }

}
