/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** reset_fds.c
*/

#include "client_prototype.h"

static int reset_write_fds(client_t *client)
{
    FD_ZERO(&client->write_fds);
    FD_SET(client->socket.socket_fd, &client->write_fds);
    return client->socket.socket_fd;
}

static int reset_read_fds(client_t *client)
{
    FD_ZERO(&client->read_fds);
    FD_SET(0, &client->read_fds);
    FD_SET(client->socket.socket_fd, &client->read_fds);
    return client->socket.socket_fd;
}

void reset_fds(client_t *client)
{
    int last_fd = 0;
    int tmp_fd = 0;
    struct timeval timeval = {0, 0};

    tmp_fd = reset_write_fds(client);
    last_fd = (last_fd > tmp_fd) ? last_fd : tmp_fd;
    tmp_fd = reset_read_fds(client);
    last_fd = (last_fd > tmp_fd) ? last_fd : tmp_fd;
    select(last_fd + 1, &client->read_fds, &client->write_fds, NULL, &timeval);
}
