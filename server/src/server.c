/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** server.c
*/

#include "server_prototype.h"

static int launch_server(const char **env, server_t *server,
    const char *input_port)
{
    const unsigned short port = atoi(input_port);

    if (load_server(server, port) == 84) {
        return 84;
    }
    loop(server);
    return 0;
}

char *completion_detect_word(const char *buf)
{
    int i = 0;
    const char *command = NULL;

    while (i < NO_INPUT_COMMAND) {
        command = input_command_list[i].name;
        if (strncmp(command, buf, strlen(buf)) == 0) {
            return strdup(&command[strlen(buf)]);
        }
        i += 1;
    }
    return NULL;
}

int server(const int ac, const char **av, const char **env)
{
    server_t server;
    int status = check_args(ac, av, 2, "./server/usage.md");

    completion_function = completion_detect_word;
    if (completion)
        init_term();
    memset(&server, 0, sizeof(server_t));
    if (status != 0) {
        return (status - 1);
    }
    status = launch_server(env, &server, av[1]);
    unload_server(&server);
    if (completion)
        restore_term();
    return status;
}
