/*
** EPITECH PROJECT, 2023
** my str cat
** File description:
** my str cat
*/

#include "my_radar.h"

char *my_strcat(char *dest, char const *src)
{
    char tmp[my_strlen(dest) + my_strlen(src) + 1];
    int m = 0;
    int i = 0;

    for (i = 0; dest[i] != '\0'; i += 1) {
        tmp[i] = dest[i];
    }
    while (src[m] != '\0') {
        tmp[i] = src[m];
        i += 1;
        m += 1;
    }
    tmp[i] = '\0';
    for (i = 0; tmp[i] != '\0'; i += 1) {
        dest[i] = tmp[i];
    }
    dest[i] = '\0';
    return (dest);
}
