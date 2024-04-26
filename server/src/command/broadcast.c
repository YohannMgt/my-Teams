/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** help.c
*/

#include "server_prototype.h"

void broadcast_command(server_t *server, user_t *user, packet_t *packet)
{
    char *message = packet->args[0];
    user_t *tmp_user = NULL;

    for (unsigned int i = 0; i < server->users->size(server->users); i++) {
        tmp_user = server->users->at(server->users, i);
        if (tmp_user->nsock != user->nsock)
            tmp_user->send(tmp_user, "%s: %s\n", user->account->name, message);
    }
    user->send(user, "%d: Broadcast sent\n", OK);
}
