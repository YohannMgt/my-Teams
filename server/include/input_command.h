/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** command.h
*/

#pragma once

#define NO_INPUT_COMMAND 3

typedef struct server_s server_t;

typedef struct input_command {
    const char *name;
    void (*func)(server_t *server);
} input_command_t;

void display(server_t *server);
void clear(server_t *server);

extern const input_command_t input_command_list[NO_INPUT_COMMAND];
