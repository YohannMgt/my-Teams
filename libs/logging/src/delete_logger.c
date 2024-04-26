/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** delete_logger.c
*/

#include "../include/logging.h"

void delete_server_logger(server_logger_t *logger)
{
    if (logger == NULL) {
        return;
    }
    if (logger->dlloader != NULL) {
        delete_dlloader(logger->dlloader);
    }
    free(logger);
}

void delete_client_logger(client_logger_t *logger)
{
    if (logger == NULL) {
        return;
    }
    if (logger->dlloader != NULL) {
        delete_dlloader(logger->dlloader);
    }
    free(logger);
}
