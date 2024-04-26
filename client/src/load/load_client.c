/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** load_client.c
*/

#include "client_prototype.h"

int load_client(client_t *client, const unsigned int address,
    const unsigned short port)
{
    memset(client, 0, sizeof(client_t));
    if (init_client(&client->socket, address, port) == 84) {
        close(client->socket.socket_fd);
        return 84;
    }
    if (client->socket.connect(&client->socket) == -1) {
        return 84;
    }
    client->debugging = false;
    client->reading_buffer = create_buffer();
    client->sending_buffer = create_buffer();
    return 0;
}
