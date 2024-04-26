/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** loop.c
*/

#include "client_prototype.h"

void login_handler(client_t *client, codes_t code, char *response)
{
    char **data;

    if (code != OK)
        return;
    data = split(response, ": ");
    if (!data || len_array((void **)data) < 2)
        return;
    client_event_logged_in(data[1], data[0]);
    client->username = strdup(data[0]);
    client->user_uuid = strdup(data[1]);
    delete_array((void **)data);
}
