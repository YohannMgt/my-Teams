/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** display.c
*/

#include "../include/include.h"

void display_uuid(uuid_t uuid)
{
    char line[64];

    uuid_unparse(uuid, line);
    printf("%s", line);
}
