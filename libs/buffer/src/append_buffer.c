/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** append_buffer.c
*/

#include "../include/buffer.h"

void append_buffer(buffer_t *buffer, char *string)
{
    unsigned int i = 0;
    unsigned int offset = 0;

    if (buffer == NULL || string == NULL) {
        return;
    }
    while (string[i] != 0) {
        offset = buffer->write_nozzle % BUFFER_SIZE;
        buffer->buffer[offset] = string[i];
        buffer->add_write_nozzle(buffer, 1);
        i += 1;
    }
}
