/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** loop.c
*/

#include "client_prototype.h"

void subscribe_handler(client_t *client, codes_t code, char *response)
{
    char **data = split(response, ":");

    if (!data)
        return;
    if (code != CSUBSCRIBED)
        return delete_array((void **)data);
    client_print_subscribed(data[0], data[1]);
}

void unsubscribe_handler(client_t *client, codes_t code, char *response)
{
    char **data = split(response, ":");

    if (!data)
        return;
    if (code != CUNSUBSCRIBED)
        return delete_array((void **)data);
    client_print_unsubscribed(data[0], data[1]);
}
