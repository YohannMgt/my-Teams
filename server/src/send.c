/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** send.c
*/

#include "server_prototype.h"

static unsigned int get_next_pos(buffer_t *buffer)
{
    unsigned int i = buffer->read_nozzle;

    while (i < BUFFER_SIZE) {
        if (i == buffer->write_nozzle) {
            break;
        }
        i += 1;
    }
    return i;
}

static void send_user_buffer(user_t *user)
{
    unsigned int read_size = 0;
    unsigned int src = user->sending_buffer->read_nozzle;
    unsigned int dest = get_next_pos(user->sending_buffer);
    unsigned int to_write = dest - src;

    if (to_write > 0) {
        read_size = write(user->nsock, &user->sending_buffer->buffer[src],
            to_write);
        user->sending_buffer->add_read_nozzle(user->sending_buffer, read_size);
    }
}

void send_buffer(server_t *server)
{
    unsigned int i = 0;
    user_t *user = NULL;

    while (i < server->users->size(server->users)) {
        user = server->users->at(server->users, i);
        if (FD_ISSET(user->nsock, &server->write_fds)) {
            send_user_buffer(user);
        }
        i += 1;
    }
}
