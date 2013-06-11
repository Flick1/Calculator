#include <curses.h>
#include <string>
#include <cstring>
#include <sstream>

#include "Screen.h"
#include "Operations.h"

int main()
{
    WINDOW *win[33];
    MEVENT mouseinput;
    int height = 25, width = 75; //Main window size.
    char* num[] = { "c", "per", "(", ")", "log", "x!",
                    "7", "8", "9", "/", "sin", "ln",
                    "4", "5", "6", "x", "cos", "pi",
                    "1", "2", "3", "-", "tan", "e",
                    "0", ".", "=", "+", "srt", "EXP" };

    initscr();
    noecho();
    cbreak();

    int startY = 0;
    int startX = 3;

    refresh();

    win[2] = newwin(height, width, startY, startX);
    Screen::create_screen(win[2], 0, 0);

    startY += 4;
    startX += 1;

    for (size_t x = 0; x < 30; x++)
    {
        win[x + 3] = newwin(height = 4, width = 6, startY, startX);
        Screen::create_screen(win[x + 3], 2, 2, TRUE, num[x], FALSE);

        if (x == 5 || x == 11 || x == 17 || x == 23)
        {
            startY += 4;
            startX -= 30;
        }
        else
            startX += 6;
    }

    keypad(win[2], TRUE);
    int c = 0;
    int key = 0;
    int select = 0;

    //START EXPRESSION HEAD OF CALCULATOR
    win[0] = newwin(3, 48, 1, 4);
    box(win[0], 0, 0);
    wrefresh(win[0]);

    int head_y, head_x;
    getparyx(win[0], head_y, head_x);
    head_y += 2;
    head_x += 3;
    //END EXPRESSION HEAD OF CALCULATOR

    //START RESULT HEAD OF CALCULATOR
    win[1] = newwin(3, 24, 1, 52);
    box(win[1], 0, 0);
    wrefresh(win[1]);

    int res_y, res_x;
    getparyx(win[1], res_y, res_x);
    res_y += 2;
    res_x += 3;
    //END RESULT HEAD OF CALCULATOR

    //START VARIABLES TO MANAGE STRING
    std::string display;
    std::string buffer;
    size_t c_parenCnt = 0;
    size_t eraseLimit = 0;
    bool dot_vacant = true;
    //END VARIABLES TO MANAGE STRINGS

    while (1)
    {
        height = 25; width = 50;
        startY = 4;
        startX = 4;

        c = wgetch(win[2]);

        for (size_t x = 0; x < 30; x++)
        {
            win[x + 3] = newwin(height = 4, width = 6, startY, startX);
            Screen::create_screen(win[x + 3], 2, 2, TRUE, num[x], FALSE);

            if (x == 5 || x == 11 || x == 17 || x == 23)
            {
                startY += 4;
                startX -= 30;
            }
            else
                startX += 6;
        }

        switch(c)
        {
            case KEY_DOWN:
                key += 6;
                select += 6;
                if (key >= 0 && key < 30)
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);
                else
                {
                    key -= 6;
                    select -= 6;
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);
                }
                break;
            case KEY_UP:
                key -= 6;
                select -= 6;
                if (key >= 0 && key <= 30)
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);
                else
                {
                    key += 6;
                    select += 6;
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);
                }
                break;
            case KEY_RIGHT:
                key += 1;
                select += 1;
                if (key > 0 && key < 30)
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);
                else
                {
                    key -= 1;
                    select -= 1;
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);
                }
                break;
            case KEY_LEFT:
                key -= 1;
                select -= 1;
                if (key >= 0 && key < 30)
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);
                else
                {
                    key += 1;
                    select += 1;
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);
                }
                break;

            //Numerical and dot
            case 10:
                if (key == 18)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "1");
                    head_x += 1;
                    display.push_back('1');
                    buffer.push_back('1');
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    ++eraseLimit;
                }

                if (key == 19)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "2");
                    head_x += 1;
                    display.push_back('2');
                    buffer.push_back('2');
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    ++eraseLimit;
                }
                if (key == 20)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "3");
                    head_x += 1;
                    display.push_back('3');
                    buffer.push_back('3');
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    ++eraseLimit;
                }
                if (key == 12)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "4");
                    head_x += 1;
                    display.push_back('4');
                    buffer.push_back('4');
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    ++eraseLimit;
                }
                if (key == 13)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "5");
                    head_x += 1;
                    display.push_back('5');
                    buffer.push_back('5');
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    ++eraseLimit;
                }
                if (key == 14)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "6");
                    head_x += 1;
                    display.push_back('6');
                    buffer.push_back('6');
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    ++eraseLimit;
                }
                if (key == 6)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "7");
                    head_x += 1;
                    display.push_back('7');
                    buffer.push_back('7');
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    ++eraseLimit;
                }
                if (key == 7)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "8");
                    head_x += 1;
                    display.push_back('8');
                    buffer.push_back('8');
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    ++eraseLimit;
                }
                if (key == 8)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "9");
                    head_x += 1;
                    display.push_back('9');
                    buffer.push_back('9');
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    ++eraseLimit;
                }
                if (key == 24)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "0");
                    head_x += 1;
                    display.push_back('0');
                    buffer.push_back('0');
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    ++eraseLimit;
                }

                if (key == 25)
                {
                    if (dot_vacant)
                    {
                        Screen::create_screen(win[0], head_x, head_y, TRUE, ".");
                        head_x += 1;
                        display.push_back('.');
                        buffer.push_back('.');

                        dot_vacant = false;
                        ++eraseLimit;
                    }

                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);
                }

            //Basic operations
                if (key == 9)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "/");
                    head_x += 1;
                    display.push_back('/');
                    buffer.insert(buffer.size(), " / ");
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    dot_vacant = true;
                    ++eraseLimit;
                }
                if (key == 15)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "x");
                    head_x += 1;
                    display.push_back('x');
                    buffer.insert(buffer.size(), " x ");
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    dot_vacant = true;
                    ++eraseLimit;
                }
                if (key == 27)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "+");
                    head_x += 1;
                    display.push_back('+');
                    buffer.insert(buffer.size(), " + ");
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    dot_vacant = true;
                    ++eraseLimit;
                }
                if (key == 21)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "-");
                    head_x += 1;
                    display.push_back('-');
                    buffer.insert(buffer.size(), " - ");
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    dot_vacant = true;
                    ++eraseLimit;
                }

                //Parentheses
                if (key == 2)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "(");
                    head_x += 1;
                    display.push_back('(');
                    buffer.insert(buffer.size(), " ( ");
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    ++c_parenCnt;
                    dot_vacant = true;
                    ++eraseLimit;
                }
                if (key == 3)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, ")");
                    head_x += 1;
                    display.push_back(')');
                    buffer.insert(buffer.size(), " ) ");
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    dot_vacant = true;
                    ++eraseLimit;

                    if (c_parenCnt > 0)
                    {
                        --c_parenCnt;
                    }
                }

                //Special operations
                if (key == 4)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "log(");
                    head_x += 4;
                    display.insert(display.size(), "log(");
                    buffer.insert(buffer.size(), " ( log ( ");
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    c_parenCnt += 2;
                    dot_vacant = true;
                    ++eraseLimit;
                }
                if (key == 10)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "sin(");
                    head_x += 4;
                    display.insert(display.size(), "sin(");
                    buffer.insert(buffer.size(), " ( sin ( ");
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    c_parenCnt += 2;
                    dot_vacant = true;
                    ++eraseLimit;
                }
                if (key == 16)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "cos(");
                    head_x += 4;
                    display.insert(display.size(), "cos(");
                    buffer.insert(buffer.size(), " ( cos ( ");
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    c_parenCnt += 2;
                    dot_vacant = true;
                    ++eraseLimit;
                }
                if (key == 22)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "tan(");
                    head_x += 4;
                    display.insert(display.size(), "tan(");
                    buffer.insert(buffer.size(), " ( tan ( ");
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    c_parenCnt += 2;
                    dot_vacant = true;
                    ++eraseLimit;
                }
                if (key == 28)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "srt(");
                    head_x += 4;
                    display.insert(display.size(), "srt(");
                    buffer.insert(buffer.size(), " ( srt ( ");
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    c_parenCnt += 2;
                    dot_vacant = true;
                    ++eraseLimit;
                }

                if (key == 11)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "ln(");
                    head_x += 3;
                    display.insert(display.size(), "ln(");
                    buffer.insert(buffer.size(), " ( ln ( ");
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    c_parenCnt += 2;
                    dot_vacant = true;
                    ++eraseLimit;
                }

            //Misc operations
            if (key == 1)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "per");
                    head_x += 3;
                    display.insert(display.size(), "per");
                    buffer.insert(buffer.size(), " per ");
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    dot_vacant = true;
                    ++eraseLimit;
                }

            if (key == 5)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "!");
                    head_x += 1;
                    display.push_back('!');
                    buffer.insert(buffer.size(), " ! ");
                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                    dot_vacant = true;
                    ++eraseLimit;
                }

                if (key == 29)
                    {
                        Screen::create_screen(win[0], head_x, head_y, TRUE, "E");
                        head_x += 1;
                        display.push_back('E');
                        buffer.insert(buffer.size(), " E ");
                        Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                        dot_vacant = true;
                        ++eraseLimit;
                    }

                if (key == 17)
                    {
                        Screen::create_screen(win[0], head_x, head_y, TRUE, "pi");
                        head_x += 2;
                        display.insert(display.size(), "pi");
                        buffer.insert(buffer.size(), " ( 3.14159265359 ) ");
                        Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                        dot_vacant = true;
                        ++eraseLimit;
                    }

                if (key == 23)
                    {
                        Screen::create_screen(win[0], head_x, head_y, TRUE, "e");
                        head_x += 1;
                        display.insert(display.size(), "e");
                        buffer.insert(buffer.size(), " ( 2.71828182846 ) ");
                        Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);

                        dot_vacant = true;
                        ++eraseLimit;
                    }

            //Management functions
                if (key == 26) //Equals
                {
                    while (c_parenCnt > 0)
                    {
                        display.insert(display.size(), ")");
                        buffer.insert(buffer.size(), " ) ");
                        --c_parenCnt;
                    }

                    getparyx(win[1], res_y, res_x);
                    res_y += 2;
                    res_x += 3;

                    if (String_Ops::chk_string(buffer))
                    {
                        double res = String_Ops::parse(buffer);
                        Screen::create_screen(win[0], head_x, head_y, TRUE, "                                             ");
                        Screen::create_screen(win[1], res_x, res_y, TRUE, String_Ops::convert_print(res));
                    }
                    else
                    {
                        Screen::create_screen(win[0], head_x, head_y, TRUE, "                                             ");
                        Screen::create_screen(win[1], res_x, res_y, TRUE, "Error          ");
                    }

                    display.erase();
                    buffer.erase();
                    dot_vacant = true;

                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);
                }

                if (key == 0) //Erase/cancel
                {
                    if (eraseLimit > 0)
                    {
                        getparyx(win[0], head_y, head_x);
                        head_y += 2;
                        head_x += 3;

                        String_Ops::eraser(buffer, display, c_parenCnt, dot_vacant);

                        char* afterErase = new char[display.length() + 1];
                        std::strcpy(afterErase, display.c_str());

                        Screen::create_screen(win[0], head_x, head_y, TRUE, "                                             ");
                        Screen::create_screen(win[0], head_x, head_y, TRUE, afterErase);
                        head_x += display.size();

                        delete []afterErase;

                        --eraseLimit;
                    }

                    Screen::create_screen(win[key + 3], 2, 2, TRUE, num[select], TRUE);
                }

                break;
        }
    }

    refresh();
    endwin();
    return 0;
}
