/*
** EPITECH PROJECT, 2024
** plane
** File description:
** plane
*/

#include "my_radar.h"

void move_plane(planes_t *plane)
{
    sfVector2f pos = sfSprite_getPosition(plane->sprite);
    float ax;
    float ay;
    float y;
    float speed = 1.0 / 60;

    speed = speed * plane->velocity;
    ax = plane->finish.x - plane->start.x;
    ay = plane->finish.y - plane->start.y;
    y = ((ax > 0) ? 1 : -1);
    pos.x += (((plane->start.x < plane->finish.x) ? 1 : -1) * speed);
    pos.y += (((ay / ax) * y) * speed);
    sfSprite_setPosition(plane->sprite, pos);
    sfRectangleShape_setPosition(plane->rectangle, pos);
}

int another_plane(planes_t *plane, planes_t **plane_all, int nb)
{
    sfVector2f pos = sfSprite_getPosition(plane->sprite);
    sfVector2f pos_plane;
    int j;

    for (int i = 0; i < plane->nb; i++) {
        if (i == nb || plane_all[i]->sprite_stat == 1)
            continue;
        pos_plane = sfSprite_getPosition(plane_all[i]->sprite);
        if (pos.x < pos_plane.x + 25 &&
            pos.x > pos_plane.x - 5 &&
            pos.y < pos_plane.y + 25 && pos.y > pos_plane.y - 5 &&
            plane->safe == 0) {
            plane->sprite_stat = 1;
            plane_all[i]->sprite_stat = 1;
            cleanup_one_plane(plane);
            cleanup_one_plane(plane_all[i]);
            j++;
        }
    }
}

void disp_plane_bis(planes_t *plane, states_s *states, tower_t **tower)
{
    sfVector2f pos;

    pos = sfSprite_getPosition(plane->sprite);
    manage_opacity(plane, states);
    sfRenderWindow_drawSprite(states->window, plane->sprite, NULL);
    sfRenderWindow_drawRectangleShape(states->window,
        plane->rectangle, NULL);
    in_tower_zone(plane, tower);
    if (pos.x >= plane->finish.x && pos.x <= plane->finish.x + 10) {
        plane->sprite_stat = 1;
        cleanup_one_plane(plane);
    }
}

void display_planes(states_s *states, planes_t **planes,
    tower_t **tower, my_timer_t *timer)
{
    int x;
    int y;
    sfVector2f pos;
    int finish = 0;

    for (int i = 0; i < states->nb_plane; i += 1) {
        if (planes[i]->sprite_stat == 1) {
            continue;
        }
        disp_plane_bis(planes[i], states, tower);
        another_plane(planes[i], planes, i);
        if (planes[i]->delay < timer->seconds)
            move_plane(planes[i]);
        finish += 1;
    }
    draw_remaining(states, finish);
    if (finish == 0)
        sfRenderWindow_close(states->window);
}
