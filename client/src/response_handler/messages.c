/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** messages.c
*/

#include "client.h"

void messages_handler(client_t *client, codes_t code, char *response)
{
    char **data = split(response, "#");
    time_t timestamp;

    if (!data || len_array((void **)data) < 4)
        return;
    timestamp = atol(data[2]);
    client_private_message_print_messages(data[0], timestamp, data[3]);
    delete_array((void **)data);
}
