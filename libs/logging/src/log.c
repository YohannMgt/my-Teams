/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** log.c
*/

#include "../include/logging.h"

void write_log(const char *str)
{
    int fd = 0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fd = open("server.log", O_WRONLY | O_APPEND, O_CREAT, 0644);
    dprintf(fd, "[%02d/%02d/%02d %02d:%02d:%02d]: %s\n", tm.tm_mday, tm.tm_mon,
        tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, str);
    close(fd);
}
