/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** loop_command.c
*/

#include "server_prototype.h"

static void perm_checker(server_t *server, packet_t *packet,
    user_t *user, int i)
{
    if (command_list[i].required > user->level)
        return (void)user->send(user, "%d: Not logged in\n", UNAUTHORIZED);
    command_list[i].func(server, user, packet);
}

static int execute_command(server_t *server, packet_t *packet, user_t *user)
{
    int i = 0;

    while (i < END) {
        if (packet->type == command_list[i].type) {
            perm_checker(server, packet, user, i);
        }
        i += 1;
    }
    return 0;
}

static int get_command(server_t *server, int i)
{
    packet_t *packet = NULL;
    unsigned int read_val = 0;
    char command[MAX_BODY_LENGTH] = {0};
    user_t *user = server->users->at(server->users, i);

    read_val = read(user->nsock, command, 512);
    if (read_val == 0) {
        return 1;
    }
    packet = parse_command(server, command);
    execute_command(server, packet, user);
    delete_packet(packet);
    return 0;
}

int loop_command(server_t *server)
{
    unsigned int i = 0;
    user_t *user = NULL;

    while (i < server->users->size(server->users)) {
        user = server->users->at(server->users, i);
        if (FD_ISSET(user->nsock, &server->read_fds)) {
            get_command(server, i);
        }
        i += 1;
    }
    return 0;
}
