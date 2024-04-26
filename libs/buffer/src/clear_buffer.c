/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** clear_buffer.c
*/

#include "../include/buffer.h"

void clear_buffer(buffer_t *buffer)
{
    if (buffer == NULL) {
        return;
    }
    memset(buffer, 0, sizeof(buffer_t));
}
