/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** convert.c
*/

#include "../include/array.h"

static unsigned int get_str_array_len(char **array)
{
    unsigned int i = 0;
    unsigned int len = 0;

    while (array[i] != NULL) {
        len += strlen(array[i]);
        i += 1;
    }
    return len;
}

char *array_to_str(char **array)
{
    unsigned int i = 0;
    unsigned int len = get_str_array_len(array);
    char *line = malloc(sizeof(char) * len);

    if (line == NULL) {
        return NULL;
    }
    line[0] = '\0';
    while (array[i] != NULL) {
        strcat(line, array[i]);
        i += 1;
    }
    return line;
}
