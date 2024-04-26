/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** unload_server.c
*/

#include "server_prototype.h"

static void unload_queue(queue_t *queue, void (*func)(void *))
{
    if (queue == NULL) {
        return;
    }
    queue->foreach(queue, func);
    delete_queue(queue);
}

void unload_server(server_t *server)
{
    if (server == NULL) {
        return;
    }
    save(server);
    if (server->socket.socket_fd != -1) {
        close(server->socket.socket_fd);
    }
    unload_queue(server->teams, (void (*)(void *))delete_team);
    unload_queue(server->users, (void (*)(void *))delete_user);
    unload_queue(server->accounts, (void (*)(void *))delete_account);
}
