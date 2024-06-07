/*
** EPITECH PROJECT, 2023
** my get nbr
** File description:
** my get nbr
*/

#include "my_radar.h"

int my_char_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int neg = 0;

    while (str[i] == '-' || str[i] == '+' || my_char_isnum(str[i])) {
        if (str[i] == '-')
            neg++;
        if (my_char_isnum(str[i]))
            nb = nb * 10 + str[i] - '0';
        if (my_char_isnum(str[i]) == 1 && my_char_isnum(str[i + 1]) == 0)
            break;
        i++;
    }
    if (neg % 2 == 1)
        nb = -nb;
    if (nb >= 2147483647 || nb <= -2147483647)
        return (0);
    return nb;
}
