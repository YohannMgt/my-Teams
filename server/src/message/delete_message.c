/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** delete_message.c
*/

#include "server_prototype.h"

void delete_message(message_t *message)
{
    if (message == NULL) {
        return;
    }
    free(message);
}
