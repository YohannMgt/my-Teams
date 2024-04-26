/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** append_array.c
*/

#include "../include/array.h"

void append_array(void **array, void *ptr)
{
    int i = 0;

    if (array == NULL || ptr == NULL) {
        return;
    }
    i = len_array(array);
    array[i] = ptr;
    array[i + 1] = NULL;
}
