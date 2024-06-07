/*
** EPITECH PROJECT, 2024
** str
** File description:
** str
*/

#include "my_radar.h"

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

char *my_strdup(char *src)
{
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (i < my_strlen(src)) {
        str[i] = src[i];
        i += 1;
    }
    str[i] = '\0';
    return (str);
}
