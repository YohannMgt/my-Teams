/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** load_server.c
*/

#include "server_prototype.h"

int load_server_history(const char **env, server_t *server)
{
    const char *value = get_env_value(env, "HOME");

    if (value != NULL) {
        strcpy(server->history_path, value);
        strcat(server->history_path, "/");
        strcat(server->history_path, HISTORY_PATH);
        return 0;
    } else {
        printf("Value is null\n");
        return 84;
    }
}

int load_server(server_t *server, const unsigned short port)
{
    memset(server, 0, sizeof(server_t));
    if (init_server(&server->socket, port) == 84) {
        close(server->socket.socket_fd);
        return 84;
    }
    if (server->socket.listen(&server->socket, port) == -1) {
        return 84;
    }
    server->teams = create_queue();
    server->users = create_queue();
    server->accounts = load_accounts(server);
    restore(server);
    return 0;
}
