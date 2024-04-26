/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** reset_fds.c
*/

#include "server_prototype.h"

static int reset_write_fds(server_t *server)
{
    unsigned int i = 0;
    int tmp_fd = 0;
    int last_fd = server->socket.socket_fd;

    FD_ZERO(&server->read_fds);
    FD_SET(0, &server->read_fds);
    FD_SET(server->socket.socket_fd, &server->read_fds);
    while (i < server->users->size(server->users)) {
        tmp_fd = ((user_t *)server->users->at(server->users, i))->nsock;
        FD_SET(tmp_fd, &server->read_fds);
        last_fd = (last_fd > tmp_fd) ? last_fd : tmp_fd;
        i += 1;
    }
    return last_fd;
}

static int reset_read_fds(server_t *server)
{
    unsigned int i = 0;
    int tmp_fd = 0;
    int last_fd = server->socket.socket_fd;

    FD_ZERO(&server->write_fds);
    FD_SET(server->socket.socket_fd, &server->read_fds);
    while (i < server->users->size(server->users)) {
        tmp_fd = ((user_t *)server->users->at(server->users, i))->nsock;
        FD_SET(tmp_fd, &server->write_fds);
        last_fd = (last_fd > tmp_fd) ? last_fd : tmp_fd;
        i += 1;
    }
    return last_fd;
}

void reset_fds(server_t *server)
{
    int last_fd = 0;
    int tmp_fd = 0;

    tmp_fd = reset_write_fds(server);
    last_fd = (last_fd > tmp_fd) ? last_fd : tmp_fd;
    tmp_fd = reset_read_fds(server);
    last_fd = (last_fd > tmp_fd) ? last_fd : tmp_fd;
    select(last_fd + 1, &server->read_fds, &server->write_fds, NULL, NULL);
}
