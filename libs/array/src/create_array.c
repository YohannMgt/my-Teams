/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** create_array.c
*/

#include "../include/array.h"

void **create_array(unsigned int size)
{
    unsigned int i = 0;
    void **array = NULL;

    if (size == 0)
        return NULL;
    array = malloc(sizeof(void *) * size);
    if (array == NULL)
        return NULL;
    while (i < size) {
        array[i] = NULL;
        i += 1;
    }
    return array;
}
