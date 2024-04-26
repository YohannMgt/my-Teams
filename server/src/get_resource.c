/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** get_team.c
*/

#include "server_prototype.h"

bool uuid_strict_compare(uuid_t *left, uuid_t *right)
{
    int status = uuid_compare(*left, *right);

    return status == 0;
}

bool account_compare(account_t **left, uuid_t *right)
{
    int status = uuid_compare((*left)->uuid, *right);

    return status == 0;
}

void *get_resource(queue_t *queue, unsigned int offset, void *cmp_arg,
    bool (*cmp_func)(void *left, void *right))
{
    unsigned int i = 0;

    if (queue == NULL) {
        return NULL;
    }
    while (i < queue->size(queue)) {
        if (cmp_func(&((char *)queue->at(queue, i))[offset], cmp_arg) == true)
            return queue->at(queue, i);
        i += 1;
    }
    return NULL;
}
