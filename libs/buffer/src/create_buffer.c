/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** create_buffer.c
*/

#include "../include/buffer.h"
#include "../include/prototype.h"

buffer_t *create_buffer(void)
{
    buffer_t *buffer = malloc(sizeof(buffer_t));

    if (buffer == NULL) {
        return NULL;
    }
    memset(buffer, 0, sizeof(buffer_t));
    buffer->delimiter = strdup("\n");
    buffer->set_read_nozzle = &set_read_nozzle;
    buffer->set_write_nozzle = &set_write_nozzle;
    buffer->add_read_nozzle = &add_read_nozzle;
    buffer->add_write_nozzle = &add_write_nozzle;
    buffer->append = &append_buffer;
    buffer->set_delimiter = &set_delimiter;
    buffer->is_ready = &is_ready;
    buffer->extract = &extract;
    return buffer;
}
