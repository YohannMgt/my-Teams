/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** read.c
*/

#include "client_prototype.h"

static void read_client_buffer(client_t *client)
{
    int read_size = 0;
    char buffer[MAX_BODY_LENGTH] = {0};

    read_size = read(client->socket.socket_fd, buffer, MAX_BODY_LENGTH - 1);
    buffer[read_size] = '\0';
    client->reading_buffer->append(client->reading_buffer, buffer);
}

void read_buffer(client_t *client)
{
    if (FD_ISSET(client->socket.socket_fd, &client->read_fds)) {
        read_client_buffer(client);
    }
}
