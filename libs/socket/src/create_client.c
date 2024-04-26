/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** create_client.c
*/

#include "../include/socket.h"

static bool init_socket_conn(socket_t *new_socket)
{
    new_socket->socket_fd = socket(AF_INET, SOCK_STREAM, 6);
    new_socket->addrlen = sizeof(new_socket->address);
    if (new_socket->socket_fd < 0) {
        perror("Socket failed");
        return false;
    } else {
        return true;
    }
}

static void set_socket_option(socket_t *socket, const int address,
    const unsigned short port)
{
    socket->address.sin_addr.s_addr = address;
    socket->address.sin_family = AF_INET;
    socket->address.sin_port = htons(port);
}

int init_client(socket_t *socket, const int address, const unsigned short port)
{
    init_socket(socket);
    if (init_socket_conn(socket) == false) {
        return 84;
    }
    set_socket_option(socket, address, port);
    return 0;
}

socket_t *create_client(const int address, const unsigned short port)
{
    socket_t *socket = malloc(sizeof(socket_t));

    if (socket == NULL) {
        return NULL;
    }
    if (init_client(socket, address, port) == 84) {
        delete_socket(socket);
        return NULL;
    }
    return socket;
}
