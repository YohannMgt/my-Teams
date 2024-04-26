/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** loop.c
*/

#include "client_prototype.h"

static command_map_t *get_command(void)
{
    static command_map_t map[] = {
            {"/help", HELP, 0, 0},
            {"/login ", LOGIN, 1, 1},
            {"/logout", LOGOUT, 0, 0},
            {"/users", USERS, 0, 0},
            {"/user", USER, 1, 1},
            {"/send ", SEND, 2, 2},
            {"/messages ", MESSAGES, 1, 1},
            {"/subscribe ", SUBSCRIBE, 1, 1},
            {"/subscribed", SUBSCRIBED, 0, 1},
            {"/unsubscribe ", UNSUBSCRIBE, 1, 1},
            {"/use", USE, 0, 3},
            {"/create ", CREATE, 1, 2},
            {"/list", LIST, 0, 0},
            {"/info", INFO, 0, 0},
            {"/broadcast ", BROADCAST, 1, 1},
            {NULL, ERROR, 0, 0}
    };

    return map;
}

static command_type_t get_command_type(char *input)
{
    command_map_t *map = get_command();

    for (int i = 0; map[i].input != NULL; i++) {
        if (strstr(input, map[i].input) != NULL)
            return (map[i].command_type);
    }
    if (input[0] == '/')
        return ERROR;
    return TEXT;
}

static vector_2d_t get_args_data(command_type_t type)
{
    for (int i = 0; get_command()[i].input != NULL; i++) {
        if (get_command()[i].command_type == type)
            return (vector_2d_t){
                get_command()[i].min_args, get_command()[i].max_args};
    }
    return (vector_2d_t){0, 0};
}

static int call_command(client_t *client, command_type_t type, char *input)
{
    vector_2d_t args_data = get_args_data(type);

    return normalize_command(client, type, input, args_data);
}

static int client_command(client_t *client, char *input)
{
    if (!strcmp(input, "/exit\n"))
        return 1 + 0 * client->socket.send(&client->socket, "%d", EXIT);
    if (!strcmp(input, "/help\n"))
        return 0 * printf(CHELP);
    if (!strcmp(input, "/debug\n")) {
        printf("Setting debugging mode to %s\n",
            client->debugging ? "false" : "true");
        client->debugging = !client->debugging;
        return 0;
    }
    return 0;
}

static int handle_input(client_t *client, char *input)
{
    command_type_t command_type;

    if (client_command(client, input))
        return 1;
    command_type = get_command_type(input);
    client->command_type = command_type;
    switch (command_type) {
        case ERROR:
        case TEXT:
            printf("Invalid command.\n");
            return 0;
        default:
            if (call_command(client, command_type, input))
                return 0 * printf("Invalid arguments.\n");
            return 0;
    }
}

static int handle_stdin(client_t *client)
{
    char *input = malloc(MAX_BODY_LENGTH * sizeof(char));
    int status;

    if (input == NULL)
        return -1 + 0 * printf("Failed to allocate memory.\n");
    if (!fgets(input, MAX_BODY_LENGTH, stdin)) {
        free(input);
        return 1;
    }
    status = handle_input(client, input);
    free(input);
    return status;
}

int loop(client_t *client)
{
    int running = true;

    while (running) {
        reset_fds(client);
        if (FD_ISSET(0, &client->read_fds)) {
            running = !handle_stdin(client);
        }
        read_buffer(client);
        if (client->reading_buffer->is_ready(client->reading_buffer)) {
            running = !response_handler(client, client->command_type);
        }
    }
    return running;
}
