/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** prototype.h
*/

#pragma once

#include "../../include/include.h"
#include "server.h"

bool uuid_strict_compare(uuid_t *left, uuid_t *right);
bool account_compare(account_t **left, uuid_t *right);
void *get_resource(queue_t *queue, unsigned int offset, void *cmp_arg,
    bool (*cmp_func)(void *left, void *right));

int server(const int ac, const char **av, const char **env);
int loop(server_t *server);
int loop_command(server_t *server);

void send_buffer(server_t *server);

void reset_fds(server_t *server);

int read_stdin(server_t *server, int *is_running);

int load_server(server_t *server, const unsigned short port);
int load_server_history(const char **env, server_t *server);
void unload_server(server_t *server);

int accept_conns(server_t *server);

packet_t *parse_command(server_t *server, char *command);

void disconnect(server_t *server);

void save(server_t *server);
void restore(server_t *server);
