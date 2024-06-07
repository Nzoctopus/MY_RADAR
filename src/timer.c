/*
** EPITECH PROJECT, 2024
** timer
** File description:
** timer
*/

#include "my_radar.h"


void time_disp(states_s *states, int time)
{
    sfFont *font = sfFont_createFromFile("rs/font.ttf");
    sfText *text = sfText_create();
    char *str = my_number_to_str(time);
    char *str2 = " s";

    my_strcat(str, str2);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, (sfVector2f){10.0, 10.0});
    sfText_setColor(text, sfBlack);
    sfRenderWindow_drawText(states->window, text, NULL);
    sfText_destroy(text);
}

void draw_remaining(states_s *states, int remain)
{
    sfFont *font = sfFont_createFromFile("rs/font.ttf");
    sfText *text = sfText_create();
    char *str = my_number_to_str(remain);
    char *str2 = " planes remaining";

    my_strcat(str, str2);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, (sfVector2f){10.0, 60.0});
    sfText_setColor(text, sfBlack);
    sfRenderWindow_drawText(states->window, text, NULL);
    sfText_destroy(text);
}

void timer(states_s *states, my_timer_t *clock)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    time_disp(states, clock->seconds);
}
