/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** remove.c
*/

#include "../include/array.h"

void remove_array(void **array, int index)
{
    int i = 0;

    if (array == NULL) {
        return;
    }
    free(array[i]);
    shift_array(array, i);
}
