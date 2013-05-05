//Currently very limited, just testing out this format and see how it gels with everyone.
//Only supports addition atm. All numbers will register, only the "+" key on the keypad will register and press "h" for result.
//I can't seem to get enter to register with the prog, so yeah "h" is a makeshift.
//Only able to support ONE operation then prog has to be closed.

//To do: 1) Write functions for commonly used set of expressions/statements.
//       2) Integrate mouse function for ease of accessing more complex operators.

//This format is like a normal calc. The thing is I think its' harder to implement considering the more complex functions
//that we have. We can always expand the width of the calc I think to fit more keys in it, but of course a list format
//is much easier when the user just has to select the operation they want to do and give numerical input.

//include Screen.cpp and BasicOps.cpp

#include <curses.h>
#include <string>
#include <sstream>
#include <set>

#include "Screen.h"
#include "Operations.h"

int main()
{
    WINDOW *win[11];
    int height = 25, width = 25;
    char num[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

    initscr();
    noecho();
    cbreak();

    int startY = (LINES - height)/2;
    int startX = (COLS - width)/2;

    refresh();

    Screen::create_screen(startY, startX, height, width, FALSE, '0');
    win[0] = Screen::create_screen(startY + 1, startX + 1, height - 21, width - 2, FALSE, '0');

    startY += 5;
    startX += 2;

    for (auto x = 0; x < 10; ++x)
    {
        win[x + 1] = Screen::create_screen(startY, startX, height - 20, width - 18, TRUE, num[x]);

        if (x == 2 || x == 5 || x == 8)
        {
            startY += 5;
            startX -= 14;
        }
        else
            startX += 7;
    }

    std::string buffer;
    size_t buff_pos = 0;
    std::string srch_buffer;
    srch_buffer.reserve(2);
    std::set<std::string> operators = { "+", "-", "%", "*" };


    double operands[2];
    size_t oper_count = 0;

    int choice;
    keypad(win[0], TRUE);

    int head_y, head_x;
    getparyx(win[0], head_y, head_x);
    head_y += 3;
    head_x += 3;

    while (1)
    {
        choice = wgetch(win[0]);
        switch(choice)
        {
            case 48:
                mvwprintw(win[0], head_y, head_x, "0");
                buffer.insert(buff_pos, "0");
                ++buff_pos;
                head_x += 1;
            case 49:
                mvwprintw(win[0], head_y, head_x, "1");
                buffer.insert(buff_pos, "1");
                ++buff_pos;
                head_x += 1;
                break;
            case 50:
                mvwprintw(win[0], head_y, head_x, "2");
                buffer.insert(buff_pos, "2");
                ++buff_pos;
                head_x += 1;
                break;
            case 51:
                mvwprintw(win[0], head_y, head_x, "3");
                buffer.insert(buff_pos, "3");
                ++buff_pos;
                head_x += 1;
                break;
            case 52:
                mvwprintw(win[0], head_y, head_x, "4");
                buffer.insert(buff_pos, "4");
                ++buff_pos;
                head_x += 1;
                break;
            case 53:
                mvwprintw(win[0], head_y, head_x, "5");
                buffer.insert(buff_pos, "5");
                ++buff_pos;
                head_x += 1;
                break;
            case 54:
                mvwprintw(win[0], head_y, head_x, "6");
                buffer.insert(buff_pos, "6");
                ++buff_pos;
                head_x += 1;
                break;
            case 56:
                mvwprintw(win[0], head_y, head_x, "7");
                buffer.insert(buff_pos, "7");
                ++buff_pos;
                head_x += 1;
                break;
            case 57:
                mvwprintw(win[0], head_y, head_x, "8");
                buffer.insert(buff_pos, "8");
                ++buff_pos;
                head_x += 1;
                break;
            case 58:
                mvwprintw(win[0], head_y, head_x, "9");
                buffer.insert(buff_pos, "9");
                ++buff_pos;
                head_x += 1;
                break;

            case 465: //Keypad "plus" key
                werase(win[0]);

                height = 25; width = 25;
                startY = (LINES - height)/2;
                startX = (COLS - width)/2;

                win[0] = Screen::create_screen(startY + 1, startX + 1, height - 21, width - 2, FALSE, '0');

                getparyx(win[0], head_y, head_x);
                head_y += 3;
                head_x += 3;

                srch_buffer = "+";
                operands[oper_count] = String_Ops::convert(buffer);
                ++oper_count;
                buff_pos = 0;
                break;
                 //Have you tried the ASCII | UNICODE for '\r' (carriage return/enter)?
            case 104: //makeshift "enter" key, press "h"
                double result;

                werase(win[0]);

                height = 25; width = 25;
                startY = (LINES - height)/2;
                startX = (COLS - width)/2;

                win[0] = Screen::create_screen(startY + 1, startX + 1, height - 21, width - 2, FALSE, '0');

                getparyx(win[0], head_y, head_x);
                head_y += 3;
                head_x += 3;

                operands[oper_count] = String_Ops::convert(buffer);
                oper_count = 0;

                    if (srch_buffer == "+")
                    {
                        result = operations::add(operands[0], operands[1]);
                        mvwprintw(win[0], head_y - 1, head_x + 10, String_Ops::convert_print(result));
                        srch_buffer.erase();
                    }
                    if (srch_buffer == "-")
                    {
                        operations::subtract(operands[0], operands[1]);

                        srch_buffer.erase();
                    }
                    if (srch_buffer == "*")
                    {
                        operations::multiply(operands[0], operands[1]);

                        srch_buffer.erase();
                    }
                    if (srch_buffer == "/")
                    {
                        operations::divide(operands[0], operands[1]);

                        srch_buffer.erase();
                    }
                break;

           /* case 43:
                werase(win[0]);

                height = 25; width = 25;
                startY = (LINES - height)/2;
                startX = (COLS - width)/2;

                win[0] = Screen::create_screen(startY + 1, startX + 1, height - 21, width - 2, FALSE, '0');

                getparyx(win[0], head_y, head_x);
                head_y += 3;
                head_x += 3;

                break; */
        }
    }

    refresh();
    endwin();
    return 0;
}
