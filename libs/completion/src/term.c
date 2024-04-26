/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** term.c
*/

#include "../include/completion.h"

void init_term(void)
{
    struct winsize winsize;
    struct termios new_term;

    ioctl(0, TIOCGWINSZ, &winsize);
    LINES = winsize.ws_row;
    COLS = winsize.ws_col;
    tcgetattr(0, &new_term);
    memcpy(&old_term, &new_term, sizeof(struct termios));
    new_term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &new_term);
}

void restore_term(void)
{
    tcsetattr(0, TCSANOW, &old_term);
}
