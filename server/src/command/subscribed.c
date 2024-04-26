/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** subscribed.c
*/

#include "server_prototype.h"

static void display_subscribed(void *arg)
{
    user_t *user = (user_t *)arg;

    user->send(user, "200 %s is subsribed\n", user->account->name);
}

static void get_user_team(server_t *server, user_t *user)
{
    unsigned int i = 0;
    team_t *team = NULL;

    user->send(user, "200 List of subscribed team: \n");
    while (i < server->teams->size(server->teams)) {
        team = server->teams->at(server->teams, i);
        if (team->subscribed->contains(team->subscribed, user)) {
            user->send(user, "%s\n", team->name);
        }
        i += 1;
    }
}

void subscribed_command(server_t *server, user_t *user, packet_t *packet)
{
    uuid_t uuid;
    team_t *team = NULL;

    if (len_array((void **)packet->args) == 1) {
        uuid_parse(packet->args[0], uuid);
        team = (team_t *)get_resource(server->teams,
            offsetof(team_t, uuid), uuid,
            (bool (*)(void *, void *))uuid_strict_compare);
        if (team != NULL) {
            team->subscribed->foreach(team->subscribed, display_subscribed);
        } else {
            user->send(user, "400 Cannot find team!\n");
        }
    } else {
        get_user_team(server, user);
    }
}
