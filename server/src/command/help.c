/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** help.c
*/

#include "server_prototype.h"

void help_command(server_t *server, user_t *user, packet_t *packet)
{
    user->send(user, "200 Help\n");
}
