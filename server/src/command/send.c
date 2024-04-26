/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** login.c
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
        return (free(filename2), filename1);
}

void save_message(char *message, uuid_t sender_uuid, uuid_t receiver_uuid)
{
    FILE *file;
    char sender_uuid_str[37];
    char receiver_uuid_str[37];
    char *filename;
    char line[74 + 4 + strlen(message)];
    time_t now = time(NULL);

    uuid_unparse(sender_uuid, sender_uuid_str);
    uuid_unparse(receiver_uuid, receiver_uuid_str);
    filename = get_filename(sender_uuid_str, receiver_uuid_str);
    if (filename == NULL)
        return;
    file = fopen(filename, "a");
    if (file == NULL)
        return free(filename);
    sprintf(line, "%s#%s#%ld#%s\n", sender_uuid_str, receiver_uuid_str, now,
        message);
    fwrite(line, 1, strlen(line), file);
    return (fclose(file), free(filename));
}

void send_command(server_t *server, user_t *user, packet_t *packet)
{
    uuid_t target_uuid;
    user_t *dest_user = NULL;

    if (uuid_parse(packet->args[0], target_uuid) == -1) {
        user->send(user, "%d: %s\n", BAD_REQUEST, "Invalid UUID");
        return;
    }
    dest_user = get_resource(server->users, offsetof(user_t, account),
        target_uuid, (bool (*)(void *, void *))account_compare);
    if (dest_user == NULL) {
        user->send(user, "%d: %s\n", BAD_REQUEST, "User not found");
        return;
    } else {
        dest_user->send(dest_user, "%d: %s: %s\n", MESSAGE_RECEIVED,
            user->account->uuid_str, packet->args[1]);
        server_event_private_message_sended(user->account->uuid_str,
            dest_user->account->uuid_str, packet->args[1]);
    }
    save_message(packet->args[1], user->account->uuid, target_uuid);
    user->send(user, "%d: %s\n", OK, "OK");
}
