/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** login.c
*/

#include "server_prototype.h"

static void account_persistance(account_t *account)
{
    int fd = open("data/users.txt", O_WRONLY | O_APPEND | O_CREAT, 0666);

    if (fd == -1) {
        return;
    }
    dprintf(fd, "%s %s\n", account->name, account->uuid_str);
    close(fd);
    return;
}

static account_t *setup_account(server_t *server, packet_t *packet)
{
    account_t *account = create_account();

    if (account == NULL) {
        return NULL;
    }
    strcpy(account->name, packet->args[0]);
    server_event_user_created(account->uuid_str, account->name);
    server->accounts->push_back(server->accounts, account);
    account_persistance(account);
    return account;
}

static account_t *find_account(server_t *server, user_t *user,
    packet_t *packet)
{
    unsigned int i = 0;
    account_t *account = NULL;

    while (i < server->accounts->size(server->accounts)) {
        account = server->accounts->at(server->accounts, i);
        if (strcmp(account->name, packet->args[0]) == 0) {
            return account;
        }
        i += 1;
    }
    return setup_account(server, packet);
}

void login_command(server_t *server, user_t *user, packet_t *packet)
{
    user_t *tmp_user;

    if (user->level >= LOGGED)
        return (void)user->send(user, "%d Already logged in\n", BAD_REQUEST);
    if (len_array((void **)packet->args) < 1)
        return (void)user->send(user, "%d Bad arguments\n", BAD_REQUEST);
    user->account = find_account(server, user, packet);
    if (user->account == NULL) {
        user->send(user, "%d: Failed to attribute account\n");
        return;
    }
    user->level = LOGGED;
    user->account->is_connected = true;
    server_event_user_logged_in(user->account->uuid_str);
    for (unsigned int i = 0; i < server->users->size(server->users); i++) {
        tmp_user = server->users->at(server->users, i);
        tmp_user->send(tmp_user, "%d: %s: %s\n", OK, user->account->name,
            user->account->uuid_str);
    }
}
