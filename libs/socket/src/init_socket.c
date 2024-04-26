/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** init_socket.c
*/

#include "../include/socket.h"

static int socket_send(struct socket_s *socket, const char *format, ...)
{
    va_list list;
    int read_val = 0;

    va_start(list, format);
    read_val = vdprintf(socket->socket_fd, format, list);
    va_end(list);
    return read_val;
}

static int socket_write(struct socket_s *socket, void *ptr, unsigned int n)
{
    return write(socket->socket_fd, ptr, n);
}

static int socket_read(struct socket_s *socket, void *ptr, unsigned int n)
{
    return read(socket->socket_fd, ptr, n);
}

static char *socket_recv(struct socket_s *socket)
{
    int read_val = 0;
    char *buf = malloc(256);

    if (buf == NULL) {
        return NULL;
    }
    read_val = read(socket->socket_fd, buf, 255);
    buf[read_val] = '\0';
    return buf;
}

static int socket_listen(struct socket_s *socket, int backlog)
{
    return listen(socket->socket_fd, backlog);
}

static int socket_accept(struct socket_s *socket, struct sockaddr *addr,
    socklen_t *len)
{
    return accept(socket->socket_fd, addr, len);
}

static int socket_connect(struct socket_s *socket)
{
    return connect(socket->socket_fd, (struct sockaddr *)&socket->address,
        socket->addrlen);
}

void init_socket(socket_t *socket)
{
    if (socket == NULL) {
        return;
    }
    memset(socket, 0, sizeof(socket_t));
    socket->socket_fd = -1;
    socket->send = socket_send;
    socket->write = socket_write;
    socket->read = socket_read;
    socket->recv = socket_recv;
    socket->listen = socket_listen;
    socket->accept = socket_accept;
    socket->connect = socket_connect;
}
