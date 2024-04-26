/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** loop.c
*/

#include "client_prototype.h"

static response_handler_t handlers[] = {
    {LOGIN, login_handler},
    {LOGOUT, logout_handler},
    {USERS, NULL},
    {USER, NULL},
    {SEND, NULL},
    {MESSAGES, messages_handler},
    {SUBSCRIBED, NULL},
    {SUBSCRIBE, NULL},
    {UNSUBSCRIBE, NULL},
    {USE, NULL},
    {CREATE, create_handler},
    {LIST, NULL},
    {INFO, NULL},
    {END, NULL}
};

static int nbr_len(int n)
{
    if (n < 10)
        return 1;
    return 1 + nbr_len(n / 10);
}

static void remove_trailing_newline(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}

static int special_bis(client_t *client, int code, char *data)
{
    if (code == CSUBSCRIBED)
        return (subscribe_handler(client, code, data), 1);
    if (code == CUNSUBSCRIBED)
        return (unsubscribe_handler(client, code, data), 1);
    if (code >= TEAM_LIST && code <= REPLY_LIST)
        return (list_handler(client, code, data), 1);
    if (code >= NOTIF_TEAM && code <= NOTIF_REPLY)
        return (create_event_handler(client, code, data), 1);
    if (code == DISCONNECTED)
        return (logout_handler(client, code, data), 1);
    return 0;
}

static int special_case(client_t *client, int code, char *data)
{
    if (code == MESSAGE_RECEIVED)
        return (send_handler(client, code, data), 1);
    if (code == MESSAGES_LIST)
        return (messages_handler(client, code, data), 1);
    if (code == CREATED)
        return (create_handler(client, code, data), 1);
    if (code >= UNKNOWN_USER && code <= UNKNOWN_THREAD)
        return (unknown_handler(client, code, data), 1);
    if (code == UNAUTHORIZED)
        return (client_error_unauthorized(), 1);
    if (code == ALREADY_EXIST)
        return (client_error_already_exist(), 1);
    if (code == USERS_LIST)
        return (users_handler(client, code, data), 1);
    if (code >= USER_PRINT && code <= THREAD_PRINT)
        return (info_handler(client, code, data), 1);
    return special_bis(client, code, data);
}

static void handler(
    client_t *client, command_type_t type, int code, char *data)
{
    if (special_case(client, code, data))
        return;
    for (int i = 0; handlers[i].type != END; i++)
        if (handlers[i].type == type && handlers[i].handler)
            return handlers[i].handler(client, code, data);
}

int response_handler(client_t *client, command_type_t type)
{
    char *response = client->reading_buffer->extract(client->reading_buffer);
    char *data = NULL;
    int code;
    int len;

    if (response == NULL)
        return 1;
    remove_trailing_newline(response);
    code = atoi(response);
    len = nbr_len(code);
    data = response + (len + 2);
    handler(client, type, code, data);
    if (client->debugging)
        printf("%s\n", response);
    return (free(response), 0);
}
