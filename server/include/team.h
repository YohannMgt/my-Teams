/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** team.h
*/

#pragma once

#include "channel.h"

typedef struct team_s {
    uuid_t uuid;
    char uuid_str[64];
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESCRIPTION_LENGTH];
    queue_t *channels;
    queue_t *subscribed;
} team_t;

team_t *create_team(void);
void delete_team(team_t *team);
