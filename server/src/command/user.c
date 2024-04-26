/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** user.c
*/

#include "server_prototype.h"

void user_command(server_t *server, user_t *user, packet_t *packet)
{
    uuid_t uuid;
    account_t *tmp;

    if (!server->accounts)
        return;
    uuid_parse(packet->args[0], uuid);
    for (unsigned int i = 0; i < server->accounts->size(server->accounts);
    i++) {
        tmp = server->accounts->at(server->accounts, i);
        if (uuid_compare(tmp->uuid, uuid) == 0) {
            user->send(user, "%d: %s#%s#%d\n", USER_PRINT, tmp->uuid_str,
                tmp->name, (tmp->is_connected) ? 1 : 0);
        }
    }
}
