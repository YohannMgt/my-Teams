/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** loop.c
*/

#include "client_prototype.h"

static void handle_thread_creation(client_t *client, char **data)
{
    time_t timestamp = atol(data[4]);

    client_print_thread_created(data[1], data[2], timestamp, data[3], data[5]);
}

void create_handler(client_t *client, codes_t code, char *response)
{
    char **data;

    if (code != CREATED)
        return;
    data = split(response, ":");
    if (!data)
        return;
    if (strcmp(data[0], "Team") == 0)
        client_print_team_created(data[1], data[2], data[3]);
    if (strcmp(data[0], "Channel") == 0)
        client_print_channel_created(data[1], data[2], data[3]);
    if (strcmp(data[0], "Thread") == 0)
        handle_thread_creation(client, data);
    if (strcmp(data[0], "Reply") == 0)
        client_print_reply_created(
            data[1], data[2], atol(data[3]), data[4]);
    delete_array((void **)data);
}

void create_event_handler(client_t *client, codes_t code, char *response)
{
    char **data;

    data = split(response, ":");
    if (!data)
        return;
    if (code == NOTIF_TEAM)
        client_event_team_created(data[0], data[1], data[2]);
    if (code == NOTIF_CHANNEL)
        client_event_channel_created(data[0], data[1], data[2]);
    if (code == NOTIF_THREAD)
        client_event_thread_created(data[0], data[1], atol(data[2]), data[3],
        data[4]);
    if (code == NOTIF_REPLY)
        client_event_thread_reply_received(data[0], data[1], data[2],
        data[3]);
}
