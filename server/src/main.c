/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** main.c
*/

#include "channel.h"
#include "server_prototype.h"

#ifdef COMPLETION
const bool completion = true;
#else
const bool completion = false;
#endif

const input_command_t input_command_list[NO_INPUT_COMMAND] = {
    {"exit", display},
    {"clear", clear},
    {"display", display}
};

const struct command_s command_list[] = {
    {HELP, NOT_LOGGED, nothing_command},
    {LOGIN, NOT_LOGGED, login_command},
    {LOGOUT, LOGGED, logout_command},
    {USERS, LOGGED, users_command},
    {USER, LOGGED, user_command},
    {SEND, LOGGED, send_command},
    {MESSAGES, LOGGED, messages_command},
    {SUBSCRIBE, LOGGED, subscribe_command},
    {SUBSCRIBED, LOGGED, subscribed_command},
    {UNSUBSCRIBE, LOGGED, unsubscribe_command},
    {USE, LOGGED, use_command},
    {CREATE, LOGGED, create_command},
    {INFO, LOGGED, info_command},
    {LIST, LOGGED, list_command},
    {EXIT, NOT_LOGGED, quit_command},
    {BROADCAST, LOGGED, broadcast_command},
};

void handler(int signum)
{
}

void debug(void)
{
    pid_t pid = getpid();

    printf("PID: %d\n", pid);
}

int main(const int ac, const char **av, const char **env)
{
    debug();
    return server(ac, av, env);
}
