/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** unknown.c
*/

#include "client_prototype.h"

void users_handler(client_t *client, codes_t code, char *response)
{
    char **data = split(response, "#");

    if (!data)
        return;
    client_print_users(data[0], data[1], data[2][0] - '0');
    delete_array((void **)data);
}
