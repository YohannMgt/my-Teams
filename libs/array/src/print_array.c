/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** print.c
*/

#include "../include/array.h"

void print_str(const void *str)
{
    printf("%s", (char *)str);
    return;
}

bool print_array(void **array, void(*print)(const void *))
{
    int i = 0;

    if (array == NULL) {
        return false;
    }
    while (array[i] != NULL) {
        print(array[i]);
        i += 1;
    }
    fflush(stdout);
    return true;
}
