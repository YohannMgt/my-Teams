/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** history.h
*/

#pragma once

#define HISTORY_PATH    ".myteams_history"

typedef struct history_s {
    char **array;
    int index;
} history_t;

history_t *load_history(void);
const char *get_history_path(void);
char *completion_detect_history_up(history_t *history);
char *completion_detect_history_down(history_t *history);
void add_history(const char *line);
