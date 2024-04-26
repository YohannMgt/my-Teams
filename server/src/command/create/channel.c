/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** channel
*/

#include "server_prototype.h"

static void display_all_channel(user_t *user, va_list list)
{
    channel_t *channel = va_arg(list, channel_t *);

    user->send(user, "%d: %s:%s:%s\n", NOTIF_CHANNEL, channel->uuid_str,
        channel->name, channel->desc);
}

void create_server_channel(server_t *server, team_t *team, user_t *user,
    packet_t *packet)
{
    channel_t *channel = create_channel();

    if (len_array((void **)packet->args) < 2 || channel == NULL) {
        delete_channel(channel);
        user->send(user, "%d: bad arguments\n", BAD_REQUEST);
        return;
    }
    channel->team = team;
    strcpy(channel->name, packet->args[0]);
    strcpy(channel->desc, packet->args[1]);
    team->channels->push_back(team->channels, channel);
    server_event_channel_created(team->uuid_str, channel->uuid_str,
        channel->name);
    user->send(user, "%d: Channel:%s:%s:%s\n", CREATED, channel->uuid_str,
        channel->name, channel->desc);
    team->subscribed->foreach_arg(team->subscribed,
        (void (*)(void *, va_list))display_all_channel, channel);
}
