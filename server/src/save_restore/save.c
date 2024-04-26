/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** save.c
*/

#include "server.h"

static void save_thread(channel_t *channel, FILE *thread_file)
{
    size_t nb_threads = channel->threads->size(channel->threads);
    thread_t *tmp;

    for (size_t i = 0; i < nb_threads; ++i) {
        tmp = channel->threads->at(channel->threads, i);
        fwrite(tmp, sizeof(thread_t), 1, thread_file);
    }
}

static void save_channel(team_t *team, FILE *channel_file, FILE *thread_file)
{
    size_t nb_channels = team->channels->size(team->channels);
    channel_t *tmp;

    for (size_t i = 0; i < nb_channels; ++i) {
        tmp = team->channels->at(team->channels, i);
        fwrite(tmp, sizeof(channel_t), 1, channel_file);
        save_thread(tmp, thread_file);
    }
}

void save(server_t *server)
{
    FILE *team_file = fopen("data/team.save", "wb");
    FILE *channel_file = fopen("data/channel.save", "wb");
    FILE *thread_file = fopen("data/thread.save", "wb");
    size_t nb_teams = server->teams->size(server->teams);
    team_t *tmp;

    if (team_file == NULL || channel_file == NULL || thread_file == NULL)
        return;
    fwrite(&nb_teams, sizeof(size_t), 1, team_file);
    for (size_t i = 0; i < nb_teams; ++i) {
        tmp = server->teams->at(server->teams, i);
        fwrite(tmp, sizeof(team_t), 1, team_file);
        save_channel(tmp, channel_file, thread_file);
    }
    fclose(team_file);
    fclose(channel_file);
    fclose(thread_file);
    // TODO : messages
}
