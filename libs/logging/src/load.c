/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** load.c
*/

#include "../include/logging.h"

int load(dlloader_t *dlloader, void *logger, int no_symbol, ...)
{
    va_list list;
    int index = 0;
    void *ptr = NULL;

    va_start(list, no_symbol);
    while (index < no_symbol) {
        ptr = dlloader->load(dlloader, va_arg(list, char *));
        if (ptr == NULL) {
            va_end(list);
            return 84;
        }
        memmove((char *)logger + index * 8, &ptr, sizeof(ptr));
        index += 1;
    }
    va_end(list);
    return 0;
}
