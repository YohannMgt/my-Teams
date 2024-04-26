/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** realloc_array.c
*/

#include "../include/array.h"

void **realloc_array(void **array, unsigned int size)
{
    unsigned int i = 0;
    void **new_array = NULL;

    if (array == NULL) {
        return create_array(size);
    }
    new_array = create_array(size);
    while (array[i] != NULL) {
        if (i > size) {
            break;
        }
        new_array[i] = array[i];
        new_array[i + 1] = NULL;
        i += 1;
    }
    delete_array(array);
    return new_array;
}
