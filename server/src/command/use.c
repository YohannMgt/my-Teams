/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** use.c
*/

#include "server_prototype.h"

static int use_thread(user_t *user, const char *arg)
{
    uuid_t uuid;
    void *resource = NULL;

    uuid_parse(arg, uuid);
    resource = get_resource(user->account->context.channel->threads,
        offsetof(thread_t, uuid), uuid,
        (bool (*)(void *, void *))uuid_strict_compare);
    if (resource == NULL) {
        user->send(user, "%d: %s\n", UNKNOWN_THREAD, arg);
        return 1;
    } else {
        user->account->context.thread = resource;
        return 0;
    }
}

static int use_channel(user_t *user, const char *arg)
{
    uuid_t uuid;
    void *resource = NULL;

    uuid_parse(arg, uuid);
    resource = get_resource(user->account->context.team->channels,
        offsetof(channel_t, uuid), uuid,
        (bool (*)(void *, void *))uuid_strict_compare);
    if (resource == NULL) {
        user->send(user, "%d: %s\n", UNKNOWN_CHANNEL, arg);
        return 1;
    } else {
        user->account->context.channel = resource;
        return 0;
    }
}

static int use_team(server_t *server, user_t *user, const char *arg)
{
    uuid_t uuid;
    void *resource = NULL;

    uuid_parse(arg, uuid);
    resource = get_resource(server->teams, offsetof(team_t, uuid),
        uuid, (bool (*)(void *, void *))uuid_strict_compare);
    if (resource == NULL) {
        user->send(user, "%d: %s\n", UNKNOWN_TEAM, arg);
        return 1;
    } else {
        user->account->context.team = resource;
        return 0;
    }
}

static void reset_context(user_t *user)
{
    user->account->context.team = NULL;
    user->account->context.channel = NULL;
    user->account->context.thread = NULL;
}

void use_command(server_t *server, user_t *user, packet_t *packet)
{
    int status = 0;

    reset_context(user);
    if (len_array((void **)packet->args) == 0)
        return (void)dprintf(user->nsock, "%d: Context reset\n", OK);
    if (len_array((void **)packet->args) >= 1)
        status += use_team(server, user, packet->args[0]);
    if (len_array((void **)packet->args) >= 2)
        status += use_channel(user, packet->args[1]);
    if (len_array((void **)packet->args) >= 3)
        status += use_thread(user, packet->args[2]);
    if (!status)
        user->send(user, "%d: Context set\n", OK);
}
