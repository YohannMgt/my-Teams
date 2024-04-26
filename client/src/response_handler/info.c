/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** unknown.c
*/

#include "client_prototype.h"

void info_handler(client_t *client, codes_t code, char *response)
{
    char **data = split(response, "#");
    time_t timestamp;

    if (!data)
        return;
    if (code == USER_PRINT)
        return (void)client_print_user(
            data[0], data[1], data[2][0] - '0');
    if (code == TEAM_PRINT)
        return (void)client_print_team(
            data[0], data[1], data[2]);
    if (code == CHANNEL_PRINT)
        return (void)client_print_channel(
            data[0], data[1], data[2]);
    if (code == THREAD_PRINT) {
        timestamp = atol(data[2]);
        return (void)client_print_thread(
            data[0], data[1], timestamp, data[3], data[4]);
    }
    delete_array((void **)data);
}
