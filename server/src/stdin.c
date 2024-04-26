/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** stdin.c
*/

#include "server_prototype.h"

static int check_exit(const char *buf, int *is_running)
{
    if (strcmp(buf, "exit") == 0) {
        *is_running = 0;
        return 1;
    } else {
        return 0;
    }
}

static void clean_str(char *buf)
{
    int i = strlen(buf) - 1;

    while (i >= 0) {
        if (buf[i] != ' ') {
            break;
        }
        buf[i] = '\0';
        i -= 1;
    }
}

static void loop_stdin_command(server_t *server, int *is_running, char *buf)
{
    int i = 0;

    while (i < NO_INPUT_COMMAND) {
        if (strcmp(buf, "exit") == 0) {
            *is_running = 0;
            return;
        }
        if (strcmp(buf, input_command_list[i].name) == 0) {
            input_command_list[i].func(server);
            return;
        }
        i += 1;
    }
    printf("Command not found\n");
    return;
}

int read_stdin(server_t *server, int *is_running)
{
    int i = 0;
    char buf[256];
    int read_val = read(0, buf, 255);

    buf[read_val - 1] = '\0';
    if (check_exit(buf, is_running) == 1) {
        return 0;
    }
    while (i < NO_INPUT_COMMAND) {
        if (strcmp(buf, input_command_list[i].name) == 0) {
            input_command_list[i].func(server);
        }
        i += 1;
    }
    return 0;
}
/*
int read_stdin(server_t *server, int *is_running)
{
    char *buf = my_readline("> ");

    if (buf == NULL) {
        return 0;
    }
    loop_stdin_command(server, is_running, buf);
    free(buf);
    return 0;
}*/
