/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** prototype.h
*/

#pragma once

#include "buffer.h"

void clear_buffer(buffer_t *buffer);
void set_write_nozzle(buffer_t *buffer, unsigned int pos);
void set_read_nozzle(buffer_t *buffer, unsigned int pos);
void add_write_nozzle(buffer_t *buffer, unsigned int pos);
void add_read_nozzle(buffer_t *buffer, unsigned int pos);
void append_buffer(buffer_t *buffer, char *string);
void set_delimiter(buffer_t *buffer, char *delimiter);
bool is_ready(buffer_t *buffer);
char *extract(buffer_t *buffer);
bool is_found(buffer_t *buffer, unsigned int pos);
