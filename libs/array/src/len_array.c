/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** array.c
*/

#include "../include/array.h"

unsigned int len_array(void **array)
{
    unsigned int i = 0;

    if (array == NULL)
        return 0;
    while (array[i] != NULL) {
        i += 1;
    }
    return i;
}
