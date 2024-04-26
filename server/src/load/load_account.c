/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** load_account.c
*/

#include "server_prototype.h"

static account_t *load_account(const char *line)
{
    char **array = split(line, " ");
    account_t *account = create_account();

    if (array == NULL || account == NULL) {
        delete_array((void **)array);
        delete_account(account);
        return NULL;
    }
    account->is_connected = false;
    strcpy(account->name, array[0]);
    strcpy(account->uuid_str, array[1]);
    uuid_parse(account->uuid_str, account->uuid);
    delete_array((void **)array);
    return account;
}

static void parse_account_array(server_t *server, char **array, queue_t *queue)
{
    int i = 0;
    account_t *account = NULL;

    while (array[i] != NULL) {
        account = load_account(array[i]);
        if (account != NULL) {
            server_event_user_loaded(account->uuid_str, account->name);
            queue->push_back(queue, account);
        }
        i += 1;
    }
}

queue_t *load_accounts(server_t *server)
{
    char **array = (char **)load_file("./data/users.txt");
    queue_t *queue = create_queue();

    if (array == NULL) {
        return queue;
    }
    parse_account_array(server, array, queue);
    delete_array((void **)array);
    return queue;
}
