/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-yohann.mangenot
** File description:
** load_file.c
*/

#include "../include/include.h"

static int get_size(FILE *file)
{
    char *line = NULL;
    unsigned long len = 0;
    unsigned int no_line = 0;

    fseek(file, 0, 0);
    while (getline(&line, &len, file) != -1) {
        no_line += 1;
    }
    free(line);
    fseek(file, 0, 0);
    return no_line;
}

static char **load_in_array(FILE *file, unsigned int no_line)
{
    int index = 0;
    unsigned long len = 0;
    unsigned int line_size = 0;
    char *line = NULL;
    char **array = (char **)create_array(no_line + 1);

    if (array == NULL) {
        return NULL;
    }
    while (getline(&line, &len, file) != -1) {
        line_size = strlen(line);
        line[line_size - 1] = '\0';
        array[index] = strdup(line);
        array[index + 1] = NULL;
        index += 1;
    }
    free(line);
    return array;
}

static char **load_file_buffer(FILE *file)
{
    int no_line = 0;

    if (file == NULL) {
        return NULL;
    }
    no_line = get_size(file);
    return load_in_array(file, no_line);
}

char **load_file(const char *path)
{
    FILE *file = fopen(path, "r");
    char **content = load_file_buffer(file);

    if (content == NULL) {
        return NULL;
    }
    fclose(file);
    return content;
}
