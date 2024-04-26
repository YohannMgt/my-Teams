/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** buffer.h
*/

#pragma once

#define _GNU_SOURCE

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 4096
#define BUF_POS(x)  (x % BUFFER_SIZE)

typedef struct buffer_s {
    unsigned int read_nozzle;
    unsigned int write_nozzle;
    char buffer[BUFFER_SIZE];
    char *delimiter;
    void (*set_read_nozzle)(struct buffer_s *buffer, unsigned int pos);
    void (*set_write_nozzle)(struct buffer_s *buffer, unsigned int pos);
    void (*add_read_nozzle)(struct buffer_s *buffer, unsigned int pos);
    void (*add_write_nozzle)(struct buffer_s *buffer, unsigned int pos);
    void (*append)(struct buffer_s *buffer, char *string);
    void (*set_delimiter)(struct buffer_s *buffer, char *delimiter);
    bool (*is_ready)(struct buffer_s *buffer);
    char *(*extract)(struct buffer_s *buffer);
} buffer_t;

buffer_t *create_buffer(void);
void delete_buffer(buffer_t *buffer);
