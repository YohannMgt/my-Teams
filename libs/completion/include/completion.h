/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** completion.h
*/

#pragma once

#include <termios.h>
#include <string.h>
#include "history.h"
#include "../../../include/include.h"
#include <sys/ioctl.h>

extern unsigned int LINES;
extern unsigned int COLS;

extern struct termios old_term;
extern char *(*completion_function)(const char *buf);

char *my_readline(const char *prompt);
void init_term(void);
void restore_term(void);
void complete(char *line);
void delete_character(char *line, char *character);
