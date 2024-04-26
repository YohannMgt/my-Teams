/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** delete_channel.c
*/

#include "server_prototype.h"

void delete_channel(channel_t *channel)
{
    if (channel == NULL) {
        return;
    }
    if (channel->threads != NULL) {
        channel->threads->foreach(channel->threads,
            (void (*)(void *))delete_thread);
        delete_queue(channel->threads);
    }
    free(channel);
}
