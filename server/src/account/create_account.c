/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** create_account.c
*/

#include "server_prototype.h"

account_t *create_account(void)
{
    account_t *account = malloc(sizeof(account_t));

    if (account == NULL) {
        return NULL;
    }
    memset(account, 0, sizeof(account_t));
    uuid_generate(account->uuid);
    uuid_unparse(account->uuid, account->uuid_str);
    return account;
}
