/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** team.c
*/

#include "server_prototype.h"

static void display_all_team(user_t *user, va_list list)
{
    team_t *team = va_arg(list, team_t *);

    user->send(user, "%d: %s:%s:%s\n", NOTIF_TEAM, team->uuid_str,
        team->name, team->desc);
}

void create_server_team(server_t *server, user_t *user, packet_t *packet)
{
    team_t *team = NULL;

    if (len_array((void **)packet->args) < 2) {
        user->send(user, "%d: bad arguments\n", BAD_REQUEST);
        return;
    }
    team = create_team();
    if (team == NULL) {
        user->send(user, "%d: Failed to create team\n", INTERNAL_ERROR);
        return;
    }
    strcpy(team->name, packet->args[0]);
    strcpy(team->desc, packet->args[1]);
    server->teams->push_back(server->teams, team);
    server->users->foreach_arg(server->users,
        (void (*)(void *, va_list))display_all_team, team);
    user->send(user, "%d: Team:%s:%s:%s\n", CREATED, team->uuid_str,
        team->name, team->desc);
    server_event_team_created(team->uuid_str, team->name,
        user->account->uuid_str);
}
