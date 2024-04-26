/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** command_parsing.c
*/

#include "server_prototype.h"

static int get_args_nb(char *input)
{
    int nb = 0;
    int idx = 0;

    while (input[idx] != '\0') {
        if (input[idx] == '"')
            nb++;
        idx++;
    }
    if (nb % 2 != 0)
        return -1;
    return nb / 2;
}

static char *get_arg(int *i, char *line)
{
    int j = *i + 1;
    char *arg = NULL;

    while (line[j] != '\0') {
        if (line[j] == '"') {
            arg = strndup(&line[*i + 1], j - *i - 1);
            *i = j;
            return arg;
        }
        j += 1;
    }
    return NULL;
}

static bool detect_arg_start(char *line, int *i)
{
    while (line[*i] != ' ') {
        if (line[*i] == '\0') {
            return false;
        }
        *i += 1;
    }
    return true;
}

static char **get_args(char *line)
{
    int i = 0;
    char *arg = NULL;
    int size = get_args_nb(line);
    char **args = (char **)create_array(size + 1);

    if (args == NULL)
        return NULL;
    if (detect_arg_start(line, &i) == false)
        return args;
    while (line[i] != '\0') {
        if (line[i] == '"') {
            arg = get_arg(&i, line);
            append_array((void **)args, arg);
        }
        i += 1;
    }
    return args;
}

packet_t *parse_command(server_t *server, char *command)
{
    char **args = NULL;
    command_type_t type = 0;
    packet_t *packet = create_packet();

    if (packet == NULL) {
        return NULL;
    }
    type = atoi(command);
    args = get_args(command);
    packet->type = type;
    packet->args = args;
    return packet;
}
