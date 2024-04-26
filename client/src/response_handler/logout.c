/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** loop.c
*/

#include "client_prototype.h"

void logout_handler(client_t *client, codes_t code, char *response)
{
    char **data = split(response, "#");

    if (code != DISCONNECTED)
        return;
    client_event_logged_out(data[0], data[1]);
}
