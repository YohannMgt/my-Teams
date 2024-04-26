/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** create.c
*/

#include "server_prototype.h"

void create_command(server_t *server, user_t *user, packet_t *packet)
{
    if (user->account->context.team == NULL) {
        create_server_team(server, user, packet);
        return;
    }
    if (user->account->context.channel == NULL) {
        create_server_channel(server, user->account->context.team, user,
            packet);
        return;
    }
    if (user->account->context.thread == NULL) {
        create_server_thread(server, user->account->context.channel, user,
            packet);
        return;
    }
    create_server_message(server, user->account->context.thread, user, packet);
    return;
}
