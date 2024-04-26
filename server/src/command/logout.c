/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** login.c
*/

#include "server_prototype.h"

void logout_command(server_t *server, user_t *user, packet_t *packet)
{
    user_t *tmp_user;

    if (user->level < LOGGED)
        return (void)user->send(user, "%d Not logged in\n", BAD_REQUEST);
    user->level = NOT_LOGGED;
    server_event_user_logged_out(user->account->uuid_str);
    for (unsigned int i = 0; i < server->users->size(server->users); i++) {
        tmp_user = server->users->at(server->users, i);
        tmp_user->send(tmp_user, "%d: %s#%s\n", DISCONNECTED,
            user->account->name, user->account->uuid_str);
    }
}
