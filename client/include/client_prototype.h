/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** client.h
*/

#pragma once

#include "client.h"

void read_buffer(client_t *client);

void login_handler(client_t *client, codes_t code, char *response);
void logout_handler(client_t *client, codes_t code, char *response);
void send_handler(client_t *client, codes_t code, char *response);
void create_handler(client_t *client, codes_t code, char *response);
void create_event_handler(client_t *client, codes_t code, char *response);
void reset_fds(client_t *client);
void unknown_handler(client_t *client, codes_t code, char *response);
void messages_handler(client_t *client, codes_t code, char *response);
void users_handler(client_t *client, codes_t code, char *response);
void info_handler(client_t *client, codes_t code, char *response);
void subscribe_handler(client_t *client, codes_t code, char *response);
void unsubscribe_handler(client_t *client, codes_t code, char *response);
void list_handler(client_t *client, codes_t code, char *response);
