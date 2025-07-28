#include "../include/terminal.hpp"

termios orig_termios;

void disableRawMode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode()
{
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode); // auto-reset on exit

    termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON); // disable canonical + echo
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}