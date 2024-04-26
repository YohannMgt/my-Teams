/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** get_env.c
*/

#include "../include/include.h"

const char *get_env_pair(const char **env, const char *key)
{
    int i = 0;

    while (env[i] != NULL) {
        if (strncmp(env[i], key, strlen(key)) == 0) {
            return env[i];
        }
        i += 1;
    }
    return NULL;
}

const char *get_env_value(const char **env, const char *key)
{
    int i = 0;
    const char *value = get_env_pair(env, key);

    if (value == NULL) {
        return NULL;
    }
    while (value[i] != '\0') {
        if (value[i] == '=') {
            return &value[i + 1];
        }
        i += 1;
    }
    return NULL;
}
