/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** cleat.c
*/

#include "../include/array.h"

void clear_array(void **array, int size)
{
    int i = 0;

    if (array == NULL) {
        return;
    }
    while (i < size) {
        array[i] = NULL;
        i += 1;
    }
    return;
}
