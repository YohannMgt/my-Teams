/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** detect_activity.c
*/

#include "../include/buffer.h"

bool is_found(buffer_t *buffer, unsigned int pos)
{
    unsigned int i = 0;

    while (buffer->delimiter[i] != '\0') {
        if (BUF_POS(pos + i) == BUF_POS(buffer->write_nozzle)) {
            return false;
        }
        if (buffer->buffer[BUF_POS(pos + i)] != buffer->delimiter[i]) {
            return false;
        }
        i += 1;
    }
    return true;
}

bool is_ready(buffer_t *buffer)
{
    unsigned int pos = 0;

    if (buffer == NULL) {
        return false;
    }
    if (buffer->read_nozzle == buffer->write_nozzle)
        return false;
    pos = buffer->read_nozzle;
    while (pos != buffer->write_nozzle) {
        if (is_found(buffer, pos)) {
            return true;
        }
        pos = BUF_POS(pos + 1);
    }
    return false;
}
