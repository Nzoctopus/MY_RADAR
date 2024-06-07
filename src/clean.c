/*
** EPITECH PROJECT, 2024
** clean
** File description:
** clean
*/

#include "my_radar.h"

void cleanup_one_plane(planes_t *planes)
{
    if (planes->sprite_stat == 0) {
            sfSprite_destroy(planes->sprite);
            sfTexture_destroy(planes->texture);
            sfRectangleShape_destroy(planes->rectangle);
    }
}

void cleanup(planes_t **planes, int nb)
{
    for (int i = 0; i < nb; i++) {
        cleanup_one_plane(planes[i]);
        free(planes[i]);
    }
    free(planes);
}

void cleanup_t(tower_t **tower, int nb)
{
    for (int i = 0; i < nb; i += 1) {
        sfSprite_destroy(tower[i]->sprite);
        sfTexture_destroy(tower[i]->texture);
        sfCircleShape_destroy(tower[i]->circle);
        free(tower[i]);
    }
    free(tower);
}
