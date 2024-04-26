/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** create_team.c
*/

#include "server_prototype.h"

team_t *create_team(void)
{
    team_t *team = malloc(sizeof(team_t));

    if (team == NULL) {
        return NULL;
    }
    memset(team, 0, sizeof(team_t));
    team->channels = create_queue();
    team->subscribed = create_queue();
    if (team->channels == NULL) {
        free(team);
        return NULL;
    }
    uuid_generate(team->uuid);
    uuid_unparse(team->uuid, team->uuid_str);
    return team;
}
