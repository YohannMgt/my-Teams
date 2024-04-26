/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** clear.
*/

#include "server_prototype.h"

void clear(server_t *server)
{
    printf("\033c");
    fflush(stdout);
}
