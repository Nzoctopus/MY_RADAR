/*
** EPITECH PROJECT, 2024
** disp
** File description:
** disp
*/

#include "my_radar.h"

void display_towers(states_s *states, tower_t **tower, int nb)
{
        for (int i = 0; i < nb; i += 1) {
            sfRenderWindow_drawSprite(states->window, tower[i]->sprite, NULL);
            sfRenderWindow_drawCircleShape(states->window,
                tower[i]->circle, NULL);
    }
}

int in_tower_zone(planes_t *plane, tower_t **tower)
{
    float distance;
    int j = 0;

    for (int i = 0; i < tower[0]->nb; i++) {
        distance = get_distance(plane, tower[i]);
        if (distance <= tower[i]->radius) {
            j++;
            plane->safe = 1;
        }
    }
    if (j == 0) {
        plane->safe = 0;
    }
}
