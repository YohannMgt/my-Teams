/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** delete_array.c
*/

#include "../include/array.h"

void delete_array_ptr(void **array, void (*func)(void *arg))
{
    unsigned int i = 0;

    if (array == NULL)
        return;
    while (array[i] != NULL) {
        func(array[i]);
        i += 1;
    }
    free(array);
    return;
}

void delete_array(void **array)
{
    unsigned int i = 0;

    if (array == NULL)
        return;
    while (array[i] != NULL) {
        free(array[i]);
        i += 1;
    }
    free(array);
    return;
}
