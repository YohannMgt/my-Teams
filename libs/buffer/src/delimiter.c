/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** delimiter
*/

#include "../include/buffer.h"

void set_delimiter(buffer_t *buffer, char *delimiter)
{
    if (buffer == NULL) {
        return;
    }
    free(buffer->delimiter);
    buffer->delimiter = strdup(delimiter);
}
