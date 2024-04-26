/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** completion.c
*/

#include "../include/completion.h"

struct termios old_term;
char *(*completion_function)(const char *buf);
unsigned int LINES;
unsigned int COLS;

static bool get_move(history_t *history, char *line, char character)
{
    char *hline = NULL;

    switch (character) {
        case 'A':
            hline = completion_detect_history_up(history);
            if (hline != NULL)
                strcpy(line, hline);
            return true;
        case 'B':
            hline = completion_detect_history_down(history);
            if (hline != NULL)
                strcpy(line, hline);
            return true;
        case 'C':
            return false;
        case 'D':
            return false;
    }
    return false;
}

static void display_line(const char *prompt, history_t *history, char *line)
{
    unsigned int i = 0;

    printf("\r");
    while (i < COLS) {
        printf(" ");
        i += 1;
    }
    printf("\r%s%s", prompt, line);
    fflush(stdout);
}

static bool detect_character(char *line, char *character)
{
    if (*character == 127) {
        delete_character(line, character);
        return true;
    }
    if (*character == '\t') {
        complete(line);
        return true;
    }
    return false;
}

static bool detect_move(history_t *history, char *line, char character)
{
    if (character == '\033') {
        character = fgetc(stdin);
        if (character == '[') {
            character = fgetc(stdin);
            return get_move(history, line, character);
        }
    } else {
        if (detect_character(line, &character) == false) {
            strncat(line, &character, 1);
        }
    }
    return false;
}

static void get_input(const char *prompt, history_t *history, char *line)
{
    char character = 0;

    while (character != EOF) {
        character = fgetc(stdin);
        if (character == '\n') {
            printf("\n");
            return;
        }
        detect_move(history, line, character);
        display_line(prompt, history, line);
    }
}

char *my_readline(const char *prompt)
{
    char *line = malloc(1024);
    history_t *history = NULL;

    if (line == NULL) {
        return NULL;
    }
    memset(line, 0, 1024);
    history = load_history();
    if (history == NULL) {
        return NULL;
    }
    memset(line, 0, 1024);
    get_input(prompt, history, line);
    add_history(line);
    return line;
}
