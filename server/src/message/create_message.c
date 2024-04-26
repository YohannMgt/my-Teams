/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** create_message.c
*/

#include "server_prototype.h"

message_t *create_message(void)
{
    message_t *message = malloc(sizeof(message_t));

    if (message == NULL) {
        return NULL;
    }
    memset(message, 0, sizeof(message_t));
    uuid_generate(message->uuid);
    uuid_unparse(message->uuid, message->uuid_str);
    return message;
}
