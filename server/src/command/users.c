/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** users.c
*/

#include "server_prototype.h"

void users_command(server_t *server, user_t *user, packet_t *packet)
{
    account_t *tmp;

    if (!server->accounts)
        return;
    for (unsigned int i = 0; i < server->accounts->size(server->accounts);
    i++) {
        tmp = server->accounts->at(server->accounts, i);
        user->send(user, "%d: %s#%s#%d\n", USERS_LIST, tmp->uuid_str,
            tmp->name, (tmp->is_connected) ? 1 : 0);
    }
    return;
}
