/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** get_context
*/

#include "server_prototype.h"

context_t get_context(user_t *user)
{
    if (user->account->context.team == NULL) {
        return NO_CONTEXT;
    }
    if (user->account->context.channel == NULL) {
        return TEAM;
    }
    if (user->account->context.thread == NULL) {
        return CHANNEL;
    }
    return THREAD;
}
