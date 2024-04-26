/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** usage.c
*/

#include "../include/include.h"

void display_usage(const char *path)
{
    int i = 0;
    char **content = load_file(path);

    if (content == NULL) {
        return;
    }
    while (content[i] != NULL) {
        printf("%s", content[i]);
        i += 1;
    }
    delete_array((void **)content);
}
