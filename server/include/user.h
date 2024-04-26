/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** user.h
*/

#pragma once

#include "../../include/include.h"
#include "account.h"

typedef enum context_e {
    NO_CONTEXT,
    TEAM,
    CHANNEL,
    THREAD,
} context_t;

typedef struct user_s {
    int nsock;
    account_t *account;
    socklen_t socklen;
    enum status_e level;
    struct sockaddr_in addr;
    buffer_t *sending_buffer;
    buffer_t *reading_buffer;
    int (*send)(struct user_s *user, const char *format, ...);
} user_t;

user_t *create_user(void);
void delete_user(user_t *user);
context_t get_context(user_t *user);
