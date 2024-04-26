/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** login.c
*/

#include "client_prototype.h"

void send_handler(client_t *client, codes_t code, char *response)
{
    char **data;
    char *spaceless;

    data = split(response, ":");
    if (!data || len_array((void **)data) < 2)
        return;
    spaceless = data[1] + 1;
    client_event_private_message_received(data[0], spaceless);
    delete_array((void **)data);
}
