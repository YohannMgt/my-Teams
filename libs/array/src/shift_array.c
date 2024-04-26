/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** shift.c
*/

#include "../include/array.h"

void shift_array(void **array, int index)
{
    if (array == NULL) {
        return;
    }
    while (array[index] != NULL) {
        array[index] = array[index + 1];
        index += 1;
    }
}
