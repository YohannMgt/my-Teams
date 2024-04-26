/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** restore.c
*/

#include "server.h"

void restore(server_t *server)
{
    FILE *team_file = fopen("data/team.save", "rb");
    FILE *channel_file = fopen("data/channel.save", "rb");
    FILE *thread_file = fopen("data/thread.save", "rb");

    if (team_file != NULL)
        fread(server->teams, sizeof(server->teams),  1, team_file);

}
