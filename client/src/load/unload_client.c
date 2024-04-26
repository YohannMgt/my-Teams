/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** unload_client.c
*/

#include "client_prototype.h"

void unload_client(client_t *client)
{
    if (client == NULL) {
        return;
    }
    free(client->username);
    free(client->user_uuid);
}
