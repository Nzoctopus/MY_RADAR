/*
** EPITECH PROJECT, 2024
** create
** File description:
** creat
*/

#include "my_radar.h"

int setup_j(int current_j, int jmax, states_s *states, char sep)
{
    int i;

    for (i = current_j; i < jmax; i++) {
        if (states->set[i] == NULL)
            break;
        if (states->set[i][0][0] == sep)
            break;
    }
    return i;
}

planes_t **create_planes(states_s *states)
{
    float x = 4.0;
    float y = 5.0;
    planes_t **planes = malloc(sizeof(planes_t *) * states->nb_plane);
    int j = 0;

    for (int i = 0; i < states->nb_plane; i += 1) {
        j = setup_j(j, states->nb_plane + states->nb_tower, states, 'A');
        if (states->set[j] == NULL)
            planes[i] = setup_plane_invalid(states->nb_plane);
        else
            planes[i] = setup_plane(states->nb_plane, states->set[j]);
        sfSprite_setTexture(planes[i]->sprite, planes[i]->texture, sfFalse);
        sfSprite_setPosition(planes[i]->sprite, planes[i]->start);
        sfRectangleShape_setPosition(planes[i]->rectangle, planes[i]->start);
        sfSprite_setScale(planes[i]->sprite, (sfVector2f){x / 57, y / 67});
        planes[i]->angle = get_angle(&(sfVector2f){planes[i]->velocity, planes[i]->velocity});
        planes[i]->safe = 0;
        j += 1;
    }
    return planes;
}

tower_t **create_tower(states_s *states)
{
    float scale = 5.0 / 128.0;
    tower_t **tower = malloc(sizeof(tower_t *) * states->nb_tower);
    int t = 0;
    int tmax = states->nb_plane + states->nb_tower;

    for (int i = 0; i < states->nb_tower; i += 1) {
        t = setup_j(t, tmax, states, 'T');
        if (states->set[t] == NULL)
            tower[i] = setup_tower_invalid(scale, states->nb_tower);
        else
            tower[i] = setup_tower(scale, states->nb_tower, states->set[t]);
        t += 1;
    }
    return tower;
}

sfRectangleShape *create_rectangle(sfVector2f position, float size)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setOutlineThickness(rectangle, 1.0);
    sfRectangleShape_setSize(rectangle, (sfVector2f){size, size});
    sfRectangleShape_setOutlineColor(rectangle, sfRed);
    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    sfRectangleShape_setPosition(rectangle, position);
    return rectangle;
}

sfRenderWindow *window_create(int width, int height, int bPP, int framerate)
{
    sfRenderWindow *w;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = bPP;
    w = sfRenderWindow_create(video_mode, "My Radar", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(w, 60);
    return w;
}
