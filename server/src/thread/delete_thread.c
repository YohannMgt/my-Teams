/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** delete_thread.c
*/

#include "server_prototype.h"

void delete_thread(thread_t *thread)
{
    if (thread == NULL) {
        return;
    }
    if (thread->messages != NULL) {
        thread->messages->foreach(thread->messages,
            (void (*)(void *))free);
        delete_queue(thread->messages);
    }
    free(thread);
}
