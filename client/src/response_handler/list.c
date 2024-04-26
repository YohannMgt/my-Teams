/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** loop.c
*/

#include "client_prototype.h"

void list_handler(client_t *client, codes_t code, char *response)
{
    char **data = split(response, "#");

    if (!data)
        return;
    if (code == TEAM_LIST)
        return (void)client_print_teams(data[0], data[1], data[2]);
    if (code == CHANNEL_LIST)
        return (void)client_team_print_channels(data[0], data[1], data[2]);
    if (code == THREAD_LIST)
        return (void)client_channel_print_threads(data[0], data[1],
        atol(data[2]), data[3], data[4]);
    if (code == REPLY_LIST)
        return (void)client_thread_print_replies(data[0], data[1],
            atol(data[2]), data[3]);
    delete_array((void **)data);
}
