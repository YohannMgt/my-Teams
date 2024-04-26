/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** accept.c
*/

#include "server_prototype.h"

static void refuse_conn(server_t *server)
{
    struct sockaddr_in addr;
    socklen_t socklen = sizeof(struct sockaddr_in);
    int nsock = server->socket.accept(&server->socket,
        (struct sockaddr *)&addr, &socklen);

    dprintf(nsock, "Failed to connect user\n");
}

static void accept_conn(server_t *server)
{
    user_t *user = create_user();

    if (user == NULL) {
        refuse_conn(server);
        return;
    }
    user->socklen = sizeof(struct sockaddr_in);
    user->nsock = server->socket.accept(&server->socket,
        (struct sockaddr *)&user->addr, &user->socklen);
    user->level = NOT_LOGGED;
    server->users->push_back(server->users, user);
    dprintf(user->nsock, "%d: Client connected\n", CONNECTED);
}

int accept_conns(server_t *server)
{
    int index = server->users->size(server->users);

    if (FD_ISSET(server->socket.socket_fd, &server->read_fds)) {
        if (index > MAX_USER) {
            refuse_conn(server);
        } else {
            accept_conn(server);
        }
    }
    return 0;
}
