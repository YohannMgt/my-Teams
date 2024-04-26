/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** unsubscribe.c
*/

#include "server_prototype.h"

static void unsubscribe_user(team_t *team, user_t *user)
{
    unsigned int i = 0;
    user_t *tmp_user = NULL;

    while (i < team->subscribed->size(team->subscribed)) {
        tmp_user = team->subscribed->at(team->subscribed, i);
        if (tmp_user == user) {
            team->subscribed->remove(team->subscribed, i);
            user->send(user, "%d: %s:%s\n", CUNSUBSCRIBED,
                user->account->uuid_str, team->uuid_str);
            return;
        }
        i += 1;
    }
    user->send(user, "%d: %s\n", UNKNOWN_TEAM, team->uuid_str);
    return;
}

void unsubscribe_command(server_t *server, user_t *user, packet_t *packet)
{
    uuid_t uuid;
    team_t *team = NULL;

    if (len_array((void **)packet->args) < 1) {
        user->send(user, "%d Bad arguments\n", BAD_REQUEST);
        return;
    }
    uuid_parse(packet->args[0], uuid);
    team = get_resource(server->teams, offsetof(team_t, uuid), uuid,
        (bool (*)(void *, void *))uuid_strict_compare);
    if (team != NULL) {
        unsubscribe_user(team, user);
        server_event_user_unsubscribed(team->uuid_str,
            user->account->uuid_str);
    } else {
        user->send(user, "%d: %S\n", UNKNOWN_TEAM, packet->args[0]);
    }
}
