/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** extract.c
*/

#include "../include/buffer.h"
#include "../include/prototype.h"

static unsigned int get_size(buffer_t *buffer)
{
    unsigned int i = 0;
    unsigned int pos = buffer->read_nozzle;

    while (pos != buffer->write_nozzle) {
        if (is_found(buffer, pos)) {
            return pos;
        }
        i = BUF_POS(i + 1);
        pos = BUF_POS(pos + 1);
    }
    return i;
}

static char *fill_string(buffer_t *buffer, unsigned int size)
{
    unsigned int i = 0;
    unsigned int pos = buffer->read_nozzle;
    char *string = malloc(sizeof(char) * size + 1);

    if (string == NULL) {
        return NULL;
    }
    memset(string, 0, size);
    while (pos != buffer->write_nozzle) {
        if (is_found(buffer, pos) == true) {
            buffer->add_read_nozzle(buffer, 1);
            break;
        }
        string[i] = buffer->buffer[pos];
        string[i + 1] = '\0';
        buffer->add_read_nozzle(buffer, 1);
        i += 1;
        pos = BUF_POS(pos + 1);
    }
    return string;
}

char *extract(buffer_t *buffer)
{
    unsigned int size = 0;

    if (buffer == NULL) {
        return NULL;
    }
    size = get_size(buffer);
    if (size == 0) {
        return NULL;
    }
    return fill_string(buffer, size);
}
