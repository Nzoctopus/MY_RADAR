/*
** EPITECH PROJECT, 2024
** setup
** File description:
** setup
*/

#include "my_radar.h"

planes_t *setup_plane(int nb, char **str)
{
    planes_t *planes;

    planes = malloc(sizeof(planes_t));
    planes->nb = nb;
    planes->sprite_stat = 0;
    planes->start = (sfVector2f){my_getnbr(str[1]), my_getnbr(str[2])};
    planes->finish = (sfVector2f){my_getnbr(str[3]), my_getnbr(str[4])};
    planes->delay = my_getnbr(str[6]);
    planes->velocity = my_getnbr(str[5]);
    planes->sprite = sfSprite_create();
    planes->texture = sfTexture_createFromFile("rs/plane.png", NULL);
    planes->rectangle = create_rectangle(planes->start, 20);
    return planes;
}

planes_t *setup_plane_invalid(int nb)
{
    planes_t *planes;

    planes = malloc(sizeof(planes_t));
    planes->delay = 5;
    planes->nb = nb;
    planes->sprite_stat = 1;
    planes->start = (sfVector2f){rand() % 1900, rand() % 1060};
    planes->finish = (sfVector2f){600, 600};
    planes->velocity = 0;
    planes->sprite = sfSprite_create();
    planes->texture = sfTexture_createFromFile("rs/plane.png", NULL);
    planes->rectangle = create_rectangle(planes->start, 20);
    return planes;
}

tower_t *setup_tower(float scale, int nb, char **str)
{
    tower_t *tower;

    tower = malloc(sizeof(tower_t));
    tower->nb = nb;
    tower->radius = my_getnbr(str[3]);
    tower->position = (sfVector2f){my_getnbr(str[1]), my_getnbr(str[2])};
    tower->circle = sfCircleShape_create();
    tower->sprite = sfSprite_create();
    tower->texture = sfTexture_createFromFile("rs/tower.png", NULL);
    sfCircleShape_setOutlineThickness(tower->circle, 2.0);
    sfCircleShape_setRadius(tower->circle, tower->radius);
    sfCircleShape_setOutlineColor(tower->circle, sfWhite);
    sfCircleShape_setFillColor(tower->circle, sfTransparent);
    sfCircleShape_setPosition(tower->circle,
        (sfVector2f){tower->position.x - tower->radius + 10,
        tower->position.y - tower->radius + 10});
    sfSprite_setTexture(tower->sprite, tower->texture, sfFalse);
    sfSprite_setScale(tower->sprite, (sfVector2f){scale, scale});
    sfSprite_setPosition(tower->sprite, tower->position);
    return tower;
}

tower_t *setup_tower_invalid(float scale, int nb)
{
    tower_t *tower;

    tower = malloc(sizeof(tower_t));
    tower->nb = nb;
    tower->radius = rand() % 300;
    tower->position = (sfVector2f){-1000, 0};
    tower->circle = sfCircleShape_create();
    tower->sprite = sfSprite_create();
    tower->texture = sfTexture_createFromFile("rs/tower.png", NULL);
    sfCircleShape_setOutlineThickness(tower->circle, 2.0);
    sfCircleShape_setRadius(tower->circle, tower->radius);
    sfCircleShape_setOutlineColor(tower->circle, sfWhite);
    sfCircleShape_setFillColor(tower->circle, sfTransparent);
    sfCircleShape_setPosition(tower->circle,
        (sfVector2f){tower->position.x - tower->radius + 10,
        tower->position.y - tower->radius + 10});
    sfSprite_setTexture(tower->sprite, tower->texture, sfFalse);
    sfSprite_setScale(tower->sprite, (sfVector2f){scale, scale});
    sfSprite_setPosition(tower->sprite, tower->position);
    return tower;
}
