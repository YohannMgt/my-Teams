/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** args.c
*/

#include "../include/include.h"

static int check_usage(const int ac, const char **av, const char *path)
{
    if (ac >= 2 && strcmp(av[1], "-help") == 0) {
        display_usage(path);
        return 1;
    } else {
        return 0;
    }
}

int check_args(
    const int ac, const char **av, const int no_arg, const char *path)
{
    if (check_usage(ac, av, path) != 0) {
        return 1;
    }
    if (ac != no_arg) {
        display_usage(path);
        return 85;
    }
    return 0;
}
