/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** quit.c
*/

#include "server_prototype.h"

void quit_command(server_t *server, user_t *user, packet_t *packet)
{
    user->level = NOT_CONNECTED;
}
