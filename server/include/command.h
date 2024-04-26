/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** command.h
*/

#pragma once

#include "../../include/command.h"

typedef struct server_s server_t;
typedef struct user_s user_t;
typedef struct channel_s channel_t;
typedef struct thread_s thread_t;
typedef struct team_s team_t;

typedef struct command_s {
    command_type_t type;
    enum status_e required;
    void (*func)(server_t *server, user_t *user, packet_t *packet);
} command_t;

void create_command(server_t *server, user_t *user, packet_t *packet);
void use_command(server_t *server, user_t *user, packet_t *packet);
void nothing_command(server_t *server, user_t *user, packet_t *packet);
void help_command(server_t *server, user_t *user, packet_t *packet);
void login_command(server_t *server, user_t *user, packet_t *packet);
void logout_command(server_t *server, user_t *user, packet_t *packet);
void quit_command(server_t *server, user_t *user, packet_t *packet);
void send_command(server_t *server, user_t *user, packet_t *packet);
void users_command(server_t *server, user_t *user, packet_t *packet);
void messages_command(server_t *server, user_t *user, packet_t *packet);
void broadcast_command(server_t *server, user_t *user, packet_t *packet);
void info_command(server_t *server, user_t *user, packet_t *packet);
void list_command(server_t *server, user_t *user, packet_t *packet);
void subscribed_command(server_t *server, user_t *user, packet_t *packet);
void subscribe_command(server_t *server, user_t *user, packet_t *packet);
void unsubscribe_command(server_t *server, user_t *user, packet_t *packet);
void user_command(server_t *server, user_t *user, packet_t *packet);

/* create command */

void create_server_message(server_t *server, thread_t *thread, user_t *user,
    packet_t *packet);
void create_server_thread(server_t *server, channel_t *channel, user_t *user,
    packet_t *packet);
void create_server_channel(server_t *server, team_t *team, user_t *user,
    packet_t *packet);
void create_server_team(server_t *server, user_t *user, packet_t *packet);

extern const struct command_s command_list[];
