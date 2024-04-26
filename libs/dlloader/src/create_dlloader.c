/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** create_dlloader.c
*/

#include "../include/dlloader.h"

static void *load(dlloader_t *this, const char *name)
{
    void *symbol = dlsym(this->handler, name);

    return symbol;
}

dlloader_t *create_dlloader(const char *path)
{
    dlloader_t *dlloader = malloc(sizeof(dlloader_t));

    if (dlloader == NULL) {
        return NULL;
    }
    dlloader->handler = dlopen(path, RTLD_LAZY);
    if (dlloader->handler == NULL) {
        free(dlloader);
        return NULL;
    }
    dlloader->load = load;
    return dlloader;
}
