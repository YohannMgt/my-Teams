/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** socket.h
*/

#pragma once

#include <dlfcn.h>
#include <stdlib.h>
#include "../../myteams/logging_client.h"
#include "../../myteams/logging_server.h"

typedef struct dlloader_s {
    void *handler;
    void *(*load)(struct dlloader_s *dlloader, const char *name);
} dlloader_t;

dlloader_t *create_dlloader(const char *path);
void delete_dlloader(dlloader_t *dlloader);
