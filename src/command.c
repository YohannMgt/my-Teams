/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** command.c
*/

#include "../include/command.h"

packet_t *create_packet(void)
{
    packet_t *packet = malloc(sizeof(packet_t));

    if (packet == NULL) {
        return NULL;
    }
    memset(packet, 0, sizeof(packet_t));
    return packet;
}

void delete_packet(packet_t *packet)
{
    if (packet == NULL) {
        return;
    }
    if (packet->args != NULL) {
        delete_array((void **)packet->args);
    }
    free(packet);
}
