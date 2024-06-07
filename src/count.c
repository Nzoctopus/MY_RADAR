/*
** EPITECH PROJECT, 2024
** count
** File description:
** count
*/

#include "my_radar.h"

void count(states_s *states)
{
    int nb_plane = 0;
    int nb_tower = 0;

    for (int i = 0; states->buffer[i] != '\0'; i++) {
        if (states->buffer[i] == 'A')
            nb_plane += 1;
        if (states->buffer[i] == 'T')
            nb_tower += 1;
    }
    states->nb_tower = nb_tower;
    states->nb_plane = nb_plane;
}
