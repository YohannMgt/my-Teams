/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** history.c
*/

#include "../../../../include/include.h"

const char *get_history_path(void)
{
    char *home = getenv("HOME");
    char *path = NULL;

    if (home == NULL) {
        free(home);
        return NULL;
    }
    path = malloc(sizeof(char) * PATH_MAX);
    if (path == NULL) {
        return NULL;
    }
    strcpy(path, home);
    strcat(path, "/");
    strcat(path, HISTORY_PATH);
    return path;
}

history_t *load_history(void)
{
    history_t *history = malloc(sizeof(history_t));
    const char *path = NULL;

    if (history == NULL) {
        return NULL;
    }
    path = get_history_path();
    if (path == NULL) {
        free(history);
        return NULL;
    }
    history->array = load_file(path);
    if (history->array == NULL) {
        history->index = 0;
        return history;
    }
    history->index = len_array((void **)history->array) - 1;
    return history;
}

void add_history(const char *line)
{
    int history_fd = 0;
    const char *path = get_history_path();

    if (path == NULL) {
        return;
    }
    history_fd = open(path, O_WRONLY | O_APPEND | O_CREAT, 0664);
    if (history_fd == -1) {
        free((void *)path);
        return;
    }
    dprintf(history_fd, "%s\n", line);
    close(history_fd);
    free((void *)path);
}

char *completion_detect_history_up(history_t *history)
{
    char *line = NULL;

    if (history == NULL || history->array == NULL) {
        return NULL;
    }
    while (history->index >= 0) {
        line = strdup(history->array[history->index]);
        line[strlen(line) - 1] = '\0';
        history->index -= 1;
        return line;
    }
    return NULL;
}

char *completion_detect_history_down(history_t *history)
{
    char *line = NULL;

    if (history == NULL || history->array == NULL) {
        return NULL;
    }
    while (history->index < (int)len_array((void **)history->array)) {
        line = strdup(history->array[history->index]);
        line[strlen(line) - 1] = '\0';
        history->index += 1;
        return line;
    }
    return NULL;
}
