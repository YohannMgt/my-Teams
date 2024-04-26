/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** add_nozzle.c
*/

#include "../include/buffer.h"

void add_read_nozzle(buffer_t *buffer, unsigned int pos)
{
    if (buffer == NULL) {
        return;
    }
    buffer->read_nozzle += pos;
    buffer->read_nozzle %= BUFFER_SIZE;
}

void add_write_nozzle(buffer_t *buffer, unsigned int pos)
{
    if (buffer == NULL) {
        return;
    }
    buffer->write_nozzle += pos;
    buffer->write_nozzle %= BUFFER_SIZE;
}
