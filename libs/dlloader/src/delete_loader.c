/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** delete_loader.c
*/

#include "../include/dlloader.h"

void delete_dlloader(dlloader_t *dlloader)
{
    if (dlloader == NULL) {
        return;
    }
    if (dlloader->handler != NULL) {
        dlclose(dlloader->handler);
    }
    free(dlloader);
}
