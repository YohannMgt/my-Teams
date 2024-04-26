/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** user.c
*/

#include "server_prototype.h"
#include <uuid/uuid.h>

static int user_send(struct user_s *user, const char *format, ...)
{
    va_list list;
    int read_val = 0;
    char *string = NULL;

    va_start(list, format);
    read_val = vasprintf(&string, format, list);
    user->sending_buffer->append(user->sending_buffer, string);
    va_end(list);
    free(string);
    return read_val;
}

user_t *create_user(void)
{
    user_t *user = malloc(sizeof(user_t));

    if (user == NULL) {
        return NULL;
    }
    memset(user, 0, sizeof(user_t));
    user->send = user_send;
    user->sending_buffer = create_buffer();
    user->reading_buffer = create_buffer();
    if (user->sending_buffer == NULL || user->reading_buffer == NULL) {
        delete_user(user);
        return NULL;
    }
    return user;
}
