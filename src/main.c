/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "my_radar.h"

void manage_opacity(planes_t *planes, states_s *states)
{
    if (states->item_opacity == 1)
        sfSprite_setColor(planes->sprite, sfTransparent);
    else
        sfSprite_setColor(planes->sprite, sfWhite);
    if (states->area_opacity == 1)
        sfRectangleShape_setOutlineColor(planes->rectangle,
            sfTransparent);
    else
        sfRectangleShape_setOutlineColor(planes->rectangle, sfRed);
}

void init_set(states_s *states)
{
    int j;
    int i;

    for (j = 0; states->settings[j] != NULL; j++)
        continue;
    states->set = malloc(sizeof(char **) * (j + 1));
    for (i = 0; i < j; i++) {
        my_mansion_to_array(states, ' ', i);
    }
    states->set[i] = NULL;
    for (int k = 0; k < i; k++) {
        if (states->set[k] == NULL)
            continue;
    }
}

void init_s(states_s *states, my_timer_t *my_timer, char **argv)
{
    my_timer->clock = sfClock_create();
    fileread(argv[1], states);
    my_str_to_array(states, '\n');
    init_set(states);
    states->window = window_create(1920, 1080, 4, 60);
    states->area_opacity = 0;
    states->item_opacity = 0;
    states->bg_sprite = sfSprite_create();
    states->bg_texture = sfTexture_createFromFile("rs/map.png", NULL);
    sfSprite_setTexture(states->bg_sprite, states->bg_texture, sfFalse);
    count(states);
}

void radar(states_s *states, planes_t **planes,
    tower_t **tower, my_timer_t *clock)
{
    manage_events(planes, states);
    sfRenderWindow_clear(states->window, sfBlack);
    sfRenderWindow_drawSprite(states->window, states->bg_sprite, NULL);
    display_planes(states, planes, tower, clock);
    display_towers(states, tower, tower[0]->nb);
    timer(states, clock);
    sfRenderWindow_display(states->window);
}

int main(int argc, char **argv)
{
    states_s states;
    planes_t **planes;
    tower_t **towers;
    my_timer_t *clock = malloc(sizeof(my_timer_t));

    if (!check(argc, argv))
        return 84;
    if (argc == 2)
        if (is_str_equal(argv[1], "-h"))
            return print_help();
    init_s(&states, clock, argv);
    planes = create_planes(&states);
    towers = create_tower(&states);
    while (sfRenderWindow_isOpen(states.window)) {
        radar(&states, planes, towers, clock);
    }
    cleanup(planes, states.nb_plane);
    cleanup_t(towers, states.nb_tower);
    sfRenderWindow_destroy(states.window);
    free(states.buffer);
}
