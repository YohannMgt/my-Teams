/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** create_thread
*/

#include "server_prototype.h"

thread_t *create_thread(void)
{
    thread_t *thread = malloc(sizeof(thread_t));

    if (thread == NULL) {
        return NULL;
    }
    memset(thread, 0, sizeof(thread_t));
    thread->messages = create_queue();
    if (thread->messages == NULL) {
        free(thread);
        return NULL;
    }
    uuid_generate(thread->uuid);
    uuid_unparse(thread->uuid, thread->uuid_str);
    return thread;
}
