/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** socket.h
*/

#pragma once

#define _GNU_SOURCE

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>

typedef struct socket_s {
    int socket_fd;
    struct sockaddr_in address;
    socklen_t addrlen;
    int (*send)(struct socket_s *socket, const char *format, ...);
    int (*write)(struct socket_s *socket, void *ptr, unsigned int n);
    int (*read)(struct socket_s *socket, void *ptr, unsigned int n);
    char *(*recv)(struct socket_s *socket);
    int (*listen)(struct socket_s *socket, int backlog);
    int (*accept)(struct socket_s *socket, struct sockaddr *addr,
        socklen_t *len);
    int (*connect)(struct socket_s *socket);
} socket_t;

socket_t *create_server(const unsigned short port);
int init_server(socket_t *socket, const unsigned short port);
socket_t *create_client(const int address, const unsigned short port);
int init_client(socket_t *socket, const int address,
    const unsigned short port);
void delete_socket(socket_t *socket);
void init_socket(socket_t *socket);
