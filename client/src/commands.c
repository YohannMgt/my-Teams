/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** loop.c
*/

#include "client_prototype.h"

static int get_length(char **array)
{
    int length;

    for (length = 0; array[length + 1] != NULL; length++);
    return length;
}

static void trim_trailing_spaces_and_newlines(char *new_str)
{
    if (*new_str) {
        while (new_str[strlen(new_str) - 1] == ' '
            || new_str[strlen(new_str) - 1] == '\n') {
            new_str[strlen(new_str) - 1] = '\0';
        }
    }
}

static int get_args_nb(char *input)
{
    int nb = 0;
    int i = 0;
    bool escape;

    while (input[i] != '\0') {
        escape = ((i == 0) ? true : input[i - 1] != '\\');
        if (input[i] == '\"' && escape) {
            nb++;
        }
        i++;
    }
    return (nb % 2 != 0 ? -1 : nb / 2);
}

static bool check_args_nb(int arg_nb, vector_2d_t args_data)
{
    return (arg_nb >= args_data.x && arg_nb <= args_data.y);
}

int normalize_command(
    client_t *client, command_type_t command_type,
    char *input, vector_2d_t args_data)
{
    char *new_str;
    char *original_str;
    int arg_nb = get_args_nb(input);
    char *space_ptr;

    if (input)
        new_str = strdup(input);
    original_str = new_str;
    if (new_str == NULL || arg_nb == -1 || !check_args_nb(arg_nb, args_data)) {
        free(original_str);
        return 1;
    }
    space_ptr = strchr(new_str, ' ');
    new_str += (space_ptr != NULL) ? (int)(space_ptr - new_str) + 1 : 0;
    new_str = (space_ptr != NULL) ? new_str : "";
    trim_trailing_spaces_and_newlines(new_str);
    client->socket.send(&client->socket, "%d %s", command_type, new_str);
    free(original_str);
    return 0;
}
