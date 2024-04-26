/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** client.h
*/

#pragma once

#include "../../include/include.h"
#include "../../include/command.h"

#define CHELP "200: Available commands:\n" H0
#define H0 H1 H2 H3 H4 H5 H6 H7 H8 H9 H10 H11 H12 H13 H14
#define H1 "\t-/help: Display available commands\n"
#define H2 "\t-/login [\"username\"]: Log in to the server\n"
#define H3 "\t-/logout: Log out from the server\n"
#define H4 "\t-/users: Get the list of all users that exist on the server\n"
#define H5 "\t-/user [\"user_uuid\"]: Get the information of a user\n"
#define H6 "\t-/send [\"user_uuid\"] [\"message\"]: Send a message to a user\n"
#define H7 "\t-/messages [\"user_uuid\"]:" H75
#define H75 "List all messages exchanged with an user\n"
#define H8 "\t-/subscribe [\"team_uuid\"]: Subscribe to a team\n"
#define H9 "\t-/subscribed ?[\"team_uuid\"]: List all subscribed teams\n"
#define H10 "\t-/unsubscribe [\"team_uuid\"]: Unsubscribe from a team\n"
#define H11 "\t-/use ?[\"team_uuid\"] ?[\"channel_uuid\"]" H115
#define H115 "?[\"thread_uuid\"]: Use specified thread\n"
#define H12 "\t-/create [\"<>_name\"] ?[\"<>_description\"]: Create a team\n"
#define H13 "\t-/list: List all teams\n"
#define H14 "\t-/info: Get information about the current user\n"

typedef struct client_s {
    socket_t socket;
    fd_set read_fds;
    fd_set write_fds;
    buffer_t *sending_buffer;
    buffer_t *reading_buffer;
    command_type_t command_type;
    char *username;
    char *user_uuid;
    bool debugging;
} client_t;

typedef struct command_map_s {
    char *input;
    command_type_t command_type;
    int min_args;
    int max_args;
} command_map_t;

typedef struct response_handler_s {
    command_type_t type;
    void (*handler)(client_t *client, codes_t code, char *response);
} response_handler_t;

int client(const int ac, const char **av);
int loop(client_t *client);

int load_client(client_t *client, const unsigned int address,
    const unsigned short port);
void unload_client(client_t *client);

int normalize_command(
    client_t *client, command_type_t command_type,
    char *input, vector_2d_t args_data);

int response_handler(client_t *client, command_type_t type);
