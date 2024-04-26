/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** delete_buffer.c
*/

#include "../include/buffer.h"

void delete_buffer(buffer_t *buffer)
{
    if (buffer == NULL) {
        return;
    }
    free(buffer);
}
