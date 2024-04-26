/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** socket.c
*/

#include "../include/socket.h"

static bool init_socket_conn(socket_t *new_socket)
{
    new_socket->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    new_socket->addrlen = sizeof(new_socket->address);
    if (new_socket->socket_fd < 0) {
        perror("Failed to create socket");
        return false;
    } else {
        return true;
    }
}

static bool set_socket_option(socket_t *socket, const unsigned short port)
{
    socket->address.sin_family = AF_INET;
    socket->address.sin_addr.s_addr = INADDR_ANY;
    socket->address.sin_port = htons(port);
    return true;
}

static bool bind_socket(socket_t *socket)
{
    int res = bind(socket->socket_fd, (struct sockaddr*)&socket->address,
        sizeof(socket->address));

    if (res < 0) {
        perror("Failed to bind socket");
        return false;
    } else {
        return true;
    }
}

int init_server(socket_t *socket, const unsigned short port)
{
    init_socket(socket);
    if (init_socket_conn(socket) == false) {
        return 84;
    }
    set_socket_option(socket, port);
    if (bind_socket(socket) == false) {
        return 84;
    }
    return 0;
}

socket_t *create_server(const unsigned short port)
{
    socket_t *socket = malloc(sizeof(socket_t));

    if (socket == NULL) {
        free(socket);
        return NULL;
    }
    if (init_server(socket, port) == -1) {
        delete_socket(socket);
        return NULL;
    }
    return socket;
}
