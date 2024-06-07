/*
** EPITECH PROJECT, 2024
** get
** File description:
** get
*/

#include "my_radar.h"

sfVector2f get_velocity(sfVector2f *start, sfVector2f *finish)
{
    sfVector2f velocity;

    velocity.x = (finish->x - start->x) * (0.017);
    velocity.y = (finish->y - start->y) * (0.017);
    return velocity;
}

double get_angle(sfVector2f *velocity)
{
    float tmp = 180.0;
    float pi = 3.14159;
    double angle;

    angle = (atan(velocity->y / velocity->x));
    angle *= (tmp / pi);
    if (velocity->x <= 0 && velocity->y <= 0)
        angle += 180;
    if (velocity->x <= 0 && velocity->y >= 0)
        angle += 180;
    if (angle >= 360)
        angle -= 360;
    return angle;
}

float get_y(planes_t *plane)
{
    float ax;
    float ay;
    float x;
    float y;

    ax = plane->finish.x - plane->start.x;
    ay = plane->finish.y - plane->start.y;
    if (ax > 0)
        x = 1;
    else
        x = -1;
    y = (ay / ax) * x;
    return y;
}

double get_distance(planes_t *plane, tower_t *tower)
{
    sfVector2f pos = sfSprite_getPosition(plane->sprite);
    sfVector2f center = sfCircleShape_getPosition(tower->circle);
    double distance;
    double ax;
    double ay;

    center.x += tower->radius;
    center.y += tower->radius;
    pos.x += 10;
    pos.y += 10;
    if (pos.x < center.x)
        ax = center.x - pos.x;
    else
        ax = pos.x - center.x;
    if (pos.y < center.y)
        ay = center.y - pos.y;
    else
        ay = pos.y - center.y;
    distance = sqrt((ax * ax) + (ay * ay));
    return distance;
}
