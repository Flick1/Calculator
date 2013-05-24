#include <curses.h>
#include <string>
#include <sstream>
#include <iostream>

#include "Screen.h"
#include "Operations.h"

int main()
{
    WINDOW *win[16];
    MEVENT mouseinput;
    int height = 21, width = 50; //Main window size.
    char* num[] = { "1", "2", "3", "/",
                    "4", "5", "6", "X",
                    "7", "8", "9", "+",
                    "0", ".", "=", "-",};

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

    for (auto x = 0; x < 16; x++)
    {
        win[x + 2] = newwin(height = 4, width = 5, startY, startX);
        Screen::create_screen(win[x + 2], 2, 2, TRUE, num[x], FALSE);

        if (x == 3 || x == 7 || x == 11)
        {
            startY += 4;
            startX -= 18;
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
    std::string srch_buffer;

    int head_y, head_x;
    getparyx(win[0], head_y, head_x);
    head_y += 2;
    head_x += 3;
    //END HEAD OF CALCULATOR

    while (1)
    {
        height = 20; width = 50;
        startY = 4;
        startX = 4;

        c = wgetch(win[1]);

        for (int x = 0; x < 16; x++)
        {
            win[x + 2] = newwin(height = 4, width = 5, startY, startX);
            Screen::create_screen(win[x + 2], 2, 2, TRUE, num[x], FALSE);

            if (x == 3 || x == 7 || x == 11)
            {
                startY += 4;
                startX -= 18;
            }
            else
                startX += 6;
        }

        switch(c)
        {
            case KEY_DOWN:
                key += 4;
                select += 4;
                if (key >= 0 && key < 16)
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                else
                {
                    key -= 4;
                    select -= 4;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                break;
            case KEY_UP:
                key -= 4;
                select -= 4;
                if (key >= 0 && key <= 16)
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                else
                {
                    key += 4;
                    select += 4;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                break;
            case KEY_RIGHT:
                key += 1;
                select += 1;
                if (key > 0 && key < 16)
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
                if (key >= 0 && key < 16)
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                else
                {
                    key += 1;
                    select += 1;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                break;
            case 10:
                if (key == 0)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "1");
                    head_x += 1;
                    buffer.insert(buff_pos, "1");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 1)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "2");
                    head_x += 1;
                    buffer.insert(buff_pos, "2");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 2)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "3");
                    head_x += 1;
                    buffer.insert(buff_pos, "3");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 4)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "4");
                    head_x += 1;
                    buffer.insert(buff_pos, "4");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 5)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "5");
                    head_x += 1;
                    buffer.insert(buff_pos, "5");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 6)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "6");
                    head_x += 1;
                    buffer.insert(buff_pos, "6");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 8)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "7");
                    head_x += 1;
                    buffer.insert(buff_pos, "7");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 9)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "8");
                    head_x += 1;
                    buffer.insert(buff_pos, "8");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 10)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "9");
                    head_x += 1;
                    buffer.insert(buff_pos, "9");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                if (key == 12)
                {
                    Screen::create_screen(win[0], head_x, head_y, TRUE, "0");
                    head_x += 1;
                    buffer.insert(buff_pos, "0");
                    ++buff_pos;
                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
            //Operations
                if (key == 3)
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
                if (key == 7)
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
                if (key == 11)
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
                if (key == 15)
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
            //Equals
                if (key == 14)
                {
                    double res = String_Ops::parse(buffer);

                    getparyx(win[0], head_y, head_x);
                    head_y += 2;
                    head_x += 3;

                    Screen::create_screen(win[0], head_x, head_y, TRUE, "             ");
                    Screen::create_screen(win[0], head_x + 30, head_y, TRUE, String_Ops::convert_print(res));

                    buff_pos = 0;

                    Screen::create_screen(win[key + 2], 2, 2, TRUE, num[select], TRUE);
                }
                break;

        }
    }

    refresh();
    endwin();
    return 0;
}
