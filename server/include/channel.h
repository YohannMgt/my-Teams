/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** channel.h
*/

#pragma once

#include "thread.h"

struct team_s;

typedef struct channel_s {
    uuid_t uuid;
    char uuid_str[64];
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESCRIPTION_LENGTH];
    uuid_t uuid_team;
    queue_t *threads;
    struct team_s *team;
} channel_t;

channel_t *create_channel(void);
void delete_channel(channel_t *channel);
