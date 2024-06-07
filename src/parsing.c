/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "my_radar.h"

void fileread(char *filepath, states_s *states)
{
    struct stat s;
    int fd = open(filepath, O_RDONLY);

    stat(filepath, &s);
    states->buffer = malloc(sizeof(char) * s.st_size);
    read(fd, states->buffer, s.st_size);
    states->buffer[s.st_size] = '\0';
    close(fd);
}

int delimiter(char *str, char sep)
{
    int delim = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == sep && str[i + 1] != sep)
            delim += 1;
        i += 1;
    }
    return delim;
}

int replace(char *str, char sep)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == sep)
            str[i] = '\0';
        i += 1;
    }
    return 0;
}

void my_str_to_array(states_s *states, char sep)
{
    int strlen = my_strlen(states->buffer);
    int strlen2 = 0;
    char *str2 = my_strdup(states->buffer);
    int j = 0;

    states->settings = malloc(sizeof(char *) * (delimiter(str2, sep) + 2));
    replace(str2, sep);
    while (strlen2 < strlen) {
        states->settings[j] = my_strdup(str2 + strlen2);
        strlen2 += my_strlen(str2 + strlen2) + 1;
        j += 1;
    }
    states->settings[j] = NULL;
    free(str2);
}

void my_mansion_to_array(states_s *states, char sep, int i)
{
    int strlen = my_strlen(states->settings[i]);
    int strlen2 = 0;
    char *str2 = my_strdup(states->settings[i]);
    int j = 0;

    states->set[i] = malloc(sizeof(char *) * (delimiter(str2, sep) + 2));
    replace(str2, sep);
    while (strlen2 < strlen) {
        states->set[i][j] = my_strdup(str2 + strlen2);
        strlen2 += my_strlen(str2 + strlen2) + 1;
        j += 1;
    }
    states->set[j] = NULL;
    free(str2);
}
