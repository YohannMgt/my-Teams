/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** create_logger.c
*/

#include "../include/logging.h"

static int set_client_logger_ptr(client_logger_t *logger)
{
    int status = load(logger->dlloader, logger, 29,
    "client_event_logged_in", "client_event_logged_out",
    "client_event_private_message_received",
    "client_event_thread_reply_received",
    "client_event_team_created",
    "client_event_channel_created", "client_event_thread_created",
    "client_print_users", "client_print_teams", "client_team_print_channels",
    "client_channel_print_threads", "client_thread_print_replies",
    "client_private_message_print_messages", "client_error_unknown_team",
    "client_error_unknown_channel", "client_error_unknown_thread",
    "client_error_unknown_user", "client_error_unauthorized",
    "client_error_already_exist", "client_print_user", "client_print_team",
    "client_print_channel", "client_print_thread", "client_print_team_created",
    "client_print_channel_created", "client_print_thread_created",
    "client_print_reply_created", "client_print_subscribed",
    "client_print_unsubscribed");

    return status;
}

client_logger_t *create_client_logger(const char *dlpath)
{
    client_logger_t *logger = malloc(sizeof(client_logger_t));

    if (logger == NULL) {
        return NULL;
    }
    logger->dlloader = create_dlloader(dlpath);
    if (logger->dlloader == NULL) {
        free(logger);
        return NULL;
    }
    if (set_client_logger_ptr(logger) == 84) {
        delete_client_logger(logger);
    }
    return logger;
}

static int set_server_logger_ptr(server_logger_t *logger)
{
    int status = load(logger->dlloader, logger, 11,
        "server_event_team_created", "server_event_channel_created",
        "server_event_thread_created", "server_event_reply_created",
        "server_event_user_subscribed", "server_event_user_unsubscribed",
        "server_event_user_created", "server_event_user_loaded",
        "server_event_user_logged_in", "server_event_user_logged_out",
        "server_event_private_message_sended");

    return status;
}

server_logger_t *create_server_logger(const char *dlpath)
{
    server_logger_t *logger = malloc(sizeof(server_logger_t));

    if (logger == NULL) {
        return NULL;
    }
    logger->dlloader = create_dlloader(dlpath);
    if (logger->dlloader == NULL) {
        free(logger);
        return NULL;
    }
    if (set_server_logger_ptr(logger) == 84) {
        delete_server_logger(logger);
    }
    return logger;
}
