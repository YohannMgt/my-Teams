/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** help.c
*/

#include "server_prototype.h"

static void info_user(user_t *user)
{
    user->send(user, "%d: %s#%s#%d\n", USER_PRINT, user->account->uuid_str,
        user->account->name, (int)user->account->is_connected);
}

static void info_team(user_t *user)
{
    user->send(user, "%d: %s#%s#%s\n", TEAM_PRINT,
        user->account->context.team->uuid_str,
        user->account->context.team->name,
        user->account->context.team->desc);
}

static void info_channel(user_t *user)
{
    user->send(user, "%d: %s#%s#%s\n", CHANNEL_PRINT,
        user->account->context.channel->uuid_str,
        user->account->context.channel->name,
        user->account->context.channel->desc);
}

static void info_thread(user_t *user)
{
    user->send(user, "%d: %s#%s#%ld#%s#%s\n", THREAD_PRINT,
        user->account->context.thread->uuid_str,
        user->account->context.thread->name,
        user->account->context.thread->timestamp,
        user->account->context.thread->name,
        user->account->context.thread->messages
            ->at(user->account->context.thread->messages, 0));
}

void info_command(server_t *server, user_t *user, packet_t *packet)
{
    context_t context = get_context(user);

    switch (context) {
        case NO_CONTEXT:
            return info_user(user);
        case TEAM:
            return info_team(user);
        case CHANNEL:
            return info_channel(user);
        case THREAD:
            return info_thread(user);
        default:
            break;
    }
}
