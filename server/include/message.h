/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** message.h
*/

#pragma once

#include "../../include/include.h"

typedef struct message_s {
    uuid_t uuid;
    char uuid_str[64];
    struct user_s *author;
    struct thread_s *thread;
    char content[MAX_BODY_LENGTH];
    time_t timestamp;
} message_t;

message_t *create_message(void);
void delete_message(message_t *message);
