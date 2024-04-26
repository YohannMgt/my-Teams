/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** display.c
*/

#include "server_prototype.h"

static void display_channel(server_t *server, team_t *team)
{
    unsigned int i = 0;
    channel_t *channel = NULL;

    while (i < team->channels->size(team->channels)) {
        channel = team->channels->at(team->channels, i);
        printf("    Channel: ");
        display_uuid(channel->uuid);
        printf("\n");
        i += 1;
    }
}

static void display_team(server_t *server)
{
    unsigned int i = 0;
    team_t *team = NULL;

    while (i < server->teams->size(server->teams)) {
        team = server->teams->at(server->teams, i);
        printf("Team: ");
        display_uuid(team->uuid);
        printf("\n");
        display_channel(server, team);
        i += 1;
    }
}

static void display_line(const char *title, uuid_t uuid)
{
    printf("\t%s: ", title);
    display_uuid(uuid);
    printf("\n");
}

static void display_user(server_t *server)
{
    unsigned int i = 0;
    user_t *user = NULL;

    while (i < server->users->size(server->users)) {
        user = server->users->at(server->users, i);
        printf("User: \n");
        if (user->account->context.team != NULL) {
            display_line("Team", user->account->context.team->uuid);
        }
        if (user->account->context.channel != NULL) {
            display_line("Channel", user->account->context.channel->uuid);
        }
        if (user->account->context.thread != NULL) {
            display_line("Thread", user->account->context.thread->uuid);
        }
        i += 1;
    }
}

void display(server_t *server)
{
    printf("Connected user(s): %d\n", server->users->size(server->users));
    display_user(server);
    display_team(server);
}
