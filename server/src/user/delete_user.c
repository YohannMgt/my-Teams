/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** delete_user.c
*/

#include "server_prototype.h"

void delete_user(user_t *user)
{
    if (user == NULL) {
        return;
    }
    if (user->nsock != -1)
        close(user->nsock);
    delete_buffer(user->sending_buffer);
    delete_buffer(user->reading_buffer);
    free(user);
}
