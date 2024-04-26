/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** disconnect
*/

#include "server_prototype.h"

void disconnect(server_t *server)
{
    unsigned int i = 0;
    user_t *user = NULL;

    while (i < server->users->size(server->users)) {
        user = server->users->at(server->users, i);
        if (user->level == NOT_CONNECTED) {
            server->users->remove(server->users, i);
            delete_user(user);
        } else {
            i += 1;
        }
    }
}
