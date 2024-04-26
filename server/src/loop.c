/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** loop.c
*/

#include "server_prototype.h"

int loop(server_t *server)
{
    int running = 1;

    while (running) {
        reset_fds(server);
        accept_conns(server);
        send_buffer(server);
        loop_command(server);
        disconnect(server);
        if (FD_ISSET(0, &server->read_fds)) {
            read_stdin(server, &running);
        }
    }
    return 0;
}
