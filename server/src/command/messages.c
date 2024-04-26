/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** help.c
*/

#include "server_prototype.h"

static char *create_filename(char *uuid1, char *uuid2)
{
    char *filename = malloc(74 + 16 + 1);

    if (!filename)
        return NULL;
    sprintf(filename, "./data/%s#%s.txt", uuid1, uuid2);
    return filename;
}

static char *get_filename(char *sender_uuid_str, char *receiver_uuid_str)
{
    char *filename1 = create_filename(sender_uuid_str, receiver_uuid_str);
    char *filename2 = create_filename(receiver_uuid_str, sender_uuid_str);
    FILE *file1;
    FILE *file2;

    if (!filename1 || !filename2)
        return (free(filename1), free(filename2), (char *)NULL);
    file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "r");
    if (file1 != NULL) {
        fclose(file1);
        return (file2) ? (fclose(file2), free(filename2), filename1)
                : (free(filename2), filename1);
    } else if (file2 != NULL) {
        fclose(file2);
        return (free(filename1), filename2);
    } else
        return (free(filename2), free(filename1), NULL);
}

static char **prepare_data(user_t *user, uuid_t receiver_uuid)
{
    char **data;
    char *filename;
    char sender_uuid_str[37];
    char receiver_uuid_str[37];

    uuid_unparse(user->account->uuid, sender_uuid_str);
    uuid_unparse(receiver_uuid, receiver_uuid_str);
    filename = get_filename(sender_uuid_str, receiver_uuid_str);
    if (!filename)
        return NULL;
    data = load_file(filename);
    free(filename);
    return data;
}

static void print_data(user_t *user, char **data)
{
    if (!data)
        return;
    for (int i = 0; data[i] != NULL; i++) {
        user->send(user, "%d: %s\n", MESSAGES_LIST, data[i]);
    }
    delete_array((void **)data);
}

static void print_history(user_t *user, uuid_t receiver_uuid)
{
    char **data = prepare_data(user, receiver_uuid);

    if (!data) {
        user->send(user, "%d: User not found\n", BAD_REQUEST);
        return;
    }
    print_data(user, data);
}

void messages_command(server_t *server, user_t *user, packet_t *packet)
{
    uuid_t target_uuid;

    if (uuid_parse(packet->args[0], target_uuid) == -1) {
        user->send(user, "%d: %s\n", BAD_REQUEST, "Invalid UUID");
        return;
    }
    return print_history(user, target_uuid);
}
