/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** help.c
*/

#include "server_prototype.h"

static void list_teams(server_t *server, user_t *user)
{
    team_t *team;

    for (unsigned int i = 0; i < server->teams->size(server->teams); i++) {
        team = server->teams->at(server->teams, i);
        user->send(user, "%d: %s#%s#%s\n", TEAM_LIST, team->uuid_str,
            team->name, team->desc);
    }
}

static void list_channels(server_t *server, user_t *user)
{
    team_t *team = user->account->context.team;
    channel_t *channel;

    for (unsigned int i = 0; i < team->channels->size(team->channels); i++) {
        channel = team->channels->at(team->channels, i);
        user->send(user, "%d: %s#%s#%s\n", CHANNEL_LIST, channel->uuid_str,
            channel->name, channel->desc);
    }
}

static void list_thread(server_t *server, user_t *user)
{
    channel_t *channel = user->account->context.channel;
    thread_t *thread;

    for (unsigned int i = 0;
        i < channel->threads->size(channel->threads); i++) {
        thread = channel->threads->at(channel->threads, i);
        user->send(user, "%d: %s#%s#%ld#%s#%s\n", THREAD_LIST,
            thread->uuid_str, thread->author->account->uuid_str,
            thread->timestamp, thread->name, thread->messages[0]);
    }
}

static void list_reply(server_t *server, user_t *user)
{
    thread_t *thread = user->account->context.thread;
    message_t *message;

    for (unsigned int i = 0; i < thread->messages->size(thread->messages);
    i++) {
        message = thread->messages->at(thread->messages, i);
        user->send(user, "%d: %s#%s#%ld#%s\n", REPLY_LIST, thread->uuid_str,
            message->author->account->uuid_str, message->timestamp,
            message->content);
    }
}

void list_command(server_t *server, user_t *user, packet_t *packet)
{
    context_t context = get_context(user);

    switch (context) {
        case NO_CONTEXT:
            return list_teams(server, user);
        case TEAM:
            return list_channels(server, user);
        case CHANNEL:
            return list_thread(server, user);
        case THREAD:
            return list_reply(server, user);
    }
}
