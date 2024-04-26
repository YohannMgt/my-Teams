/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** unknown.c
*/

#include "client_prototype.h"

void unknown_handler(client_t *client, codes_t code, char *response)
{
    char **data;

    data = split(response, ":");
    if (!data)
        return;
    if (code == UNKNOWN_USER)
        return (void)client_error_unknown_user(data[0]);
    if (code == UNKNOWN_TEAM)
        return (void)client_error_unknown_team(data[0]);
    if (code == UNKNOWN_CHANNEL)
        return (void)client_error_unknown_channel(data[0]);
    if (code == UNKNOWN_THREAD)
        return (void)client_error_unknown_thread(data[0]);
    delete_array((void **)data);
}
