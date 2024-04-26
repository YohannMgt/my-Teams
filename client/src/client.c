/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** client.c
*/

#include "client_prototype.h"

static int launch_client(client_t *client, const char *input_ip,
    const char *input_port)
{
    const unsigned short port = atoi(input_port);
    const unsigned int address = 0;
    int status = inet_pton(AF_INET, input_ip, (void *)&address);

    if (status <= 0) {
        return 84;
    }
    if (load_client(client, address, port) == 84) {
        return 84;
    }
    return loop(client);
}

int client(const int ac, const char **av)
{
    client_t client;
    int status = check_args(ac, av, 3, "./client/usage.md");

    if (status != 0) {
        return (status - 1);
    }
    status = launch_client(&client, av[1], av[2]);
    unload_client(&client);
    return status;
}
