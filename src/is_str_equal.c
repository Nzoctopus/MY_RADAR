/*
** EPITECH PROJECT, 2023
** str equal
** File description:
** str equal
*/

#include "my_radar.h"

int is_str_equal(char *str, char *str1)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] != str1[i]) {
            return 0;
            break;
        }
    }
    return 1;
}
