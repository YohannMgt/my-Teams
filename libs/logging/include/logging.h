/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** logging.h
*/

#pragma once

#define _GNU_SOURCE

#include "../../dlloader/include/dlloader.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define CSTR    const char *

int load(dlloader_t *dlloader, void *logger, int no_symbol, ...);

typedef struct server_logger_s {
    int (*team_created)(CSTR, CSTR, CSTR);
    int (*channel_created)(CSTR, CSTR, CSTR);
    int (*thread_created)(CSTR, CSTR, CSTR, CSTR, CSTR);
    int (*reply_created)(CSTR, CSTR, CSTR);
    int (*user_subscribed)(CSTR, CSTR);
    int (*user_unsubscribed)(CSTR, CSTR);
    int (*user_created)(CSTR, CSTR);
    int (*user_loaded)(CSTR, CSTR);
    int (*user_logged_in)(CSTR);
    int (*user_logged_out)(CSTR);
    int (*private_message_sended)(CSTR, CSTR, CSTR);
    dlloader_t *dlloader;
} server_logger_t;

server_logger_t *create_server_logger(const char *dlpath);
void delete_server_logger(server_logger_t *logger);

typedef struct client_logger_s {
    int (*client_event_logged_in)(CSTR, CSTR);
    int (*client_event_logged_out)(CSTR, CSTR);
    int (*client_event_private_message_received)(CSTR, CSTR);
    int (*client_event_thread_reply_received)(CSTR, CSTR, CSTR, CSTR);
    int (*client_event_team_created)(CSTR, CSTR, CSTR);
    int (*client_event_channel_created)(CSTR, CSTR, CSTR);
    int (*client_event_thread_created)(CSTR, CSTR, time_t, CSTR, CSTR);
    int (*client_print_users)(CSTR, CSTR, int);
    int (*client_print_teams)(CSTR, CSTR, CSTR);
    int (*client_team_print_channels)(CSTR, CSTR, CSTR);
    int (*client_channel_print_threads)(CSTR, CSTR, time_t, CSTR, CSTR);
    int (*client_thread_print_replies)(CSTR, CSTR, time_t, CSTR);
    int (*client_private_message_print_messages)(CSTR, time_t, CSTR);
    int (*client_error_unknown_team)(CSTR);
    int (*client_error_unknown_channel)(CSTR);
    int (*client_error_unknown_thread)(CSTR);
    int (*client_error_unknown_user)(CSTR);
    int (*client_error_unauthorized)();
    int (*client_error_already_exist)();
    int (*client_print_user)(CSTR, CSTR, int);
    int (*client_print_team)(CSTR, CSTR, CSTR);
    int (*client_print_channel)(CSTR, CSTR, CSTR);
    int (*client_print_thread)(CSTR, CSTR, time_t, CSTR, CSTR);
    int (*client_print_team_created)(CSTR, CSTR, CSTR);
    int (*client_print_channel_created)(CSTR, CSTR, CSTR);
    int (*client_print_thread_created)(CSTR, CSTR, time_t, CSTR, CSTR);
    int (*client_print_reply_created)(CSTR, CSTR, time_t, CSTR);
    int (*client_print_subscribed)(CSTR, CSTR);
    int (*client_print_unsubscribed)(CSTR, CSTR);
    dlloader_t *dlloader;
} client_logger_t;

client_logger_t *create_client_logger(const char *dlpath);
void delete_client_logger(client_logger_t *logger);
