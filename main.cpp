//Looking for some advice on this. I distinguished the operators into 3 kinds

//1) Binary operators - requires operand on both lhs and rhs
//2) Unary operators - requires operand on only the right side
//3) Unary number modifier - ie. Pi and percentage. Can either be rhs or lhs.

//Is that all that's needed? I'm not sure what EXP, Ans, e, Inv, x! and ln mean though on the Google scientific calculator.
//Also it seems tan, cos and sin functions are giving incorrect answers, at least when I compare to the calculator.

//To do: 1) Square root(s.r), percentage(per), backspace/reset(c) has yet to be implemented.
//       2) Previously mentioned functions pending due to lack of knowledge =(
//       3) Previous answer capability.
//       4) ???

#include <curses.h>
#include <string>
#include <sstream>

#include "Screen.h"
#include "Operations.h"

int main()
{
    WINDOW *win[27];
    MEVENT mouseinput;
    int height = 25, width = 50; //Main window size.
    char* num[] = { "c", "per", "(", ")", "log",
                    "7", "8", "9", "/", "sin",
                    "4", "5", "6", "x", "cos",
                    "1", "2", "3", "-", "tan",
                    "0", ".", "=", "+", "s.r" };

    initscr();
    noecho();
    cbreak();

    int startY = 0;
    int startX = 3;

    refresh();

    win[1] = newwin(height, width, startY, startX);
    Screen::create_screen(win[1], 0, 0, FALSE, "0", FALSE);

    startY += 4;
    startX += 1;

    for (size_t x = 0; x < 25; x++)
    {
        win[x + 2] = newwin(height = 4, width = 6, startY, startX);
        Screen::create_screen(win[x + 2], 2, 2, TRUE, num[x], FALSE);

        if (x == 4 || x == 9 || x == 14 || x == 19)
        {
            startY += 4;
            startX -= 24;
        }
        else
            startX += 6;
    }

    keypad(win[1], TRUE);
    int c = 0;
    int key = 0;
    int select = 0;

    //START HEAD OF CALCULATOR
    win[0] = newwin(3, 48, 1, 4);
    box(win[0], 0, 0);
    wrefresh(win[0]);

    std::string buffer;
    size_t buff_pos = 0;
    size_t c_parenCnt = 0;

    int head_y, head_x;
    getparyx(win[0], head_y, head_x);
    head_y += 2;
    head_x += 3;
    //END HEAD OF CALCULATOR

    while (1)
    {
        height = 25; width = 50;
        startY = 4;
        startX = 4;

        c = wgetch(win[1]);

        for (size_t x = 0; x < 25; x++)
        {
            win[x + 2] = newwin(height = 4, width = 6, startY, startX);
            Screen::create_screen(win[x + 2], 2, 2, TRUE, num[x], FALSE);

            if (x == 4 || x == 9 || x == 14 || x == 19)
            {
                startY += 4;
                startX -= 24;
            }
            else
                startX += 6;
        }

        switch(c)
        {
            case KEY_DOWN:
                key += 5;
                select += 5;
                if (key >= 0 && key < 25)
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                else
                {
                    key -= 5;
                    select -= 5;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                break;
            case KEY_UP:
                key -= 5;
                select -= 5;
                if (key >= 0 && key <= 25)
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                else
                {
                    key += 5;
                    select += 5;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                break;
            case KEY_RIGHT:
                key += 1;
                select += 1;
                if (key > 0 && key < 25)
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                else
                {
                    key -= 1;
                    select -= 1;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                break;
            case KEY_LEFT:
                key -= 1;
                select -= 1;
                if (key >= 0 && key < 25)
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                else
                {
                    key += 1;
                    select += 1;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                break;

            //Calculator keypad
            case 10:

                if (key == 15)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "1");
                    head_x += 1;
                    buffer.insert(buff_pos, "1");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }

                if (key == 16)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "2");
                    head_x += 1;
                    buffer.insert(buff_pos, "2");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 17)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "3");
                    head_x += 1;
                    buffer.insert(buff_pos, "3");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 10)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "4");
                    head_x += 1;
                    buffer.insert(buff_pos, "4");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 11)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "5");
                    head_x += 1;
                    buffer.insert(buff_pos, "5");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 12)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "6");
                    head_x += 1;
                    buffer.insert(buff_pos, "6");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 5)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "7");
                    head_x += 1;
                    buffer.insert(buff_pos, "7");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 6)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "8");
                    head_x += 1;
                    buffer.insert(buff_pos, "8");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 7)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "9");
                    head_x += 1;
                    buffer.insert(buff_pos, "9");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 20)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "0");
                    head_x += 1;
                    buffer.insert(buff_pos, "0");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }

            //Basic operations
                if (key == 8)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "/");
                    head_x += 1;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "/");
                    ++buff_pos;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 13)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "x");
                    head_x += 1;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "*");
                    ++buff_pos;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 23)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "+");
                    head_x += 1;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "+");
                    ++buff_pos;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 18)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "-");
                    head_x += 1;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "-");
                    ++buff_pos;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }

                //Parentheses
                if (key == 2)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "(");
                    head_x += 1;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "(");
                    ++buff_pos;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 3)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, ")");
                    head_x += 1;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, ")");
                    ++buff_pos;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);

                    if (c_parenCnt > 0)
                    {
                        --c_parenCnt;
                    }
                }

                //Special operations
                if (key == 4)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "log");
                    head_x += 3;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "log");
                    buff_pos += 3;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "(");
                    ++buff_pos;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);

                    ++c_parenCnt;

                }
                if (key == 9)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "sin");
                    head_x += 3;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "sin");
                    buff_pos += 3;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "(");
                    ++buff_pos;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);

                    ++c_parenCnt;
                }
                if (key == 14)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "cos");
                    head_x += 3;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "cos");
                    buff_pos += 3;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "(");
                    ++buff_pos;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);

                    ++c_parenCnt;
                }
                if (key == 19)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "tan");
                    head_x += 3;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "tan");
                    buff_pos += 3;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "(");
                    ++buff_pos;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);

                    ++c_parenCnt;
                }
                if (key == 24)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "s.r");
                    head_x += 3;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "s.r");
                    buff_pos += 3;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "(");
                    ++buff_pos;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);

                    ++c_parenCnt;
                }

            //Misc operations
            if (key == 1)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "per");
                    head_x += 1;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    buffer.insert(buff_pos, "per");
                    ++buff_pos;
                    buffer.insert(buff_pos, " ");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }

            //Equals
                if (key == 22)
                {
                    while (c_parenCnt > 0)
                    {
                        buffer.insert(buff_pos, " ");
                        ++buff_pos;
                        buffer.insert(buff_pos, ")");
                        ++buff_pos;
                        buffer.insert(buff_pos, " ");
                        ++buff_pos;
                        --c_parenCnt;
                    }

                    getparyx(win[0], head_y, head_x);
                    head_y += 2;
                    head_x += 3;

                    if (String_Ops::chk_string(buffer))
                    {
                        double res = String_Ops::parse(buffer);
                        Screen::create_screen(win[0], head_x, head_y, TRUE, "             ");
                        Screen::create_screen(win[0], head_x + 30, head_y, TRUE, String_Ops::convert_print(res));
                    }
                    else
                    {
                        Screen::create_screen(win[0], head_x, head_y, TRUE, "             ");
                        Screen::create_screen(win[0], head_x + 30, head_y, TRUE, "Error");
                    }

                    buff_pos = 0;
                    buffer.erase();

                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                break;



        }
    }

    refresh();
    endwin();
    return 0;
}
