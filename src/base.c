/*
** EPITECH PROJECT, 2024
** base
** File description:
** base
*/

#include "my_radar.h"

void events(planes_t **planes, states_s *states, sfEvent evt)
{
    if (evt.type == sfEvtClosed)
            sfRenderWindow_close(states->window);
    if (evt.type == sfEvtKeyPressed) {
            if (sfKeyboard_isKeyPressed(sfKeyS)) {
                states->item_opacity += 1;
                states->item_opacity %= 2;
            }
            if (sfKeyboard_isKeyPressed(sfKeyL)) {
                states->area_opacity += 1;
                states->area_opacity %= 2;
            }
        }
}

void manage_events(planes_t **planes, states_s *states)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(states->window, &event)) {
        events(planes, states, event);
    }
}

int check(int argc, char **argv)
{
    char *help = "-h";
    int fd;
    struct stat s;

    if (argc == 1) {
        write(2, "./my_radar: bad arguments:", 27);
        write(2, "0 given but 84 is required\n", 28);
        write(2, "retry with -h\n", 15);
    }
    if (argc != 2)
        return 0;
    fd = open(argv[1], O_RDONLY);
    stat(argv[1], &s);
    if (s.st_size == 0 || fd <= 0 || s.st_size > 61075)
        if (!is_str_equal(argv[1], help)) {
            write(2, "Failed to open, read, or find the script.\n", 43);
            return 0;
        }
    return 1;
}

int print_help(void)
{
    write(1, "Air traffic simulation panel\n", 30);
    write(1, "\nUSAGE\n", 8);
    write(1, "  ./my_radar [OPTIONS] path_to_script\n", 39);
    write(1, "   path_to_script     The path to the script file.", 51);
    write(1, "\n\nOPTIONS\n", 10);
    write(1, "  -h                 print the usage and quit.\n\n", 49);
    write(1, "USER INTERACTIONS\n", 19);
    write(1, "  'L' key       enable/disable hitboxes and areas.\n", 52);
    write(1, "  'S' key       enable/disable sprites.\n", 41);
    return 0;
}
