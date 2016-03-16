#include "breakout.h"

BreakOut::BreakOut()
{   initscr(); // Open curses
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    // Colours
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    endwin(); // Close curses
}
