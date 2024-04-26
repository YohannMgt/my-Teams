/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** set_nozzle.c
*/

#include "../include/buffer.h"

void set_read_nozzle(buffer_t *buffer, unsigned int pos)
{
    if (buffer == NULL) {
        return;
    }
    buffer->read_nozzle = (pos % BUFFER_SIZE);
}

void set_write_nozzle(buffer_t *buffer, unsigned int pos)
{
    if (buffer == NULL) {
        return;
    }
    buffer->write_nozzle = (pos % BUFFER_SIZE);
}
