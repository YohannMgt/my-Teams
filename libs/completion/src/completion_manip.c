/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** completion_manip.c
*/

#include "../include/completion.h"

void delete_character(char *line, char *character)
{
    int len = strlen(line);

    if (strlen(line) == 0) {
        return;
    }
    line[len - 1] = '\0';
    printf("\b \b");
    return;
}

void complete(char *line)
{
    char *command = completion_function(line);

    if (command != NULL) {
        strcat(line, command);
    }
}
