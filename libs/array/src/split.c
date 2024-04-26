/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** split.c
*/

#include "../include/array.h"

static unsigned int get_len_array(const char *string, const char *delim)
{
    char *token = NULL;
    char *copy = strdup(string);
    char *rest = copy;
    unsigned int size = 0;

    if (copy == NULL) {
        return -1;
    }
    token = strtok_r(rest, delim, &rest);
    while (token) {
        size += 1;
        token = strtok_r(rest, delim, &rest);
    }
    free(copy);
    return size;
}

static void split_token(char **array, char *string, const char *delim)
{
    int i = 0;
    char *token = NULL;
    char *rest = string;

    array[i] = NULL;
    token = strtok_r(rest, delim, &rest);
    while (token) {
        array[i] = strdup(token);
        array[i + 1] = NULL;
        i += 1;
        token = strtok_r(rest, delim, &rest);
    }
}

char **split(const char *string, const char *delim)
{
    char *copy = NULL;
    char **array = NULL;
    int size = get_len_array(string, delim);

    if (size == -1) {
        return NULL;
    }
    copy = strdup(string);
    if (copy == NULL) {
        return NULL;
    }
    array = malloc(sizeof(char *) * (size + 1));
    if (array == NULL) {
        free(copy);
        return NULL;
    }
    split_token(array, copy, delim);
    free(copy);
    return array;
}
