/*
** EPITECH PROJECT, 2023
** include
** File description:
** include
*/

#ifndef MY_RADAR
    #define MY_RADAR
    #include <SFML/Graphics/RenderWindow.h>
    #include <stdlib.h>
    #include <SFML/Config.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/Transform.h>
    #include <stdio.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Vector3.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <math.h>
    #include <sys/stat.h>
typedef struct planes {
    int delay;
    sfSprite *sprite;
    int safe;
    sfVector2f position;
    int velocity;
    sfRectangleShape *rectangle;
    sfVector2f start;
    sfVector2f finish;
    double angle;
    int sprite_stat;
    sfTexture *texture;
    int nb;
} planes_t;
typedef struct tower {
    int nb;
    int radius;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfCircleShape *circle;
} tower_t;
typedef struct states {
    int nb_tower;
    int nb_plane;
    char *buffer;
    char **settings;
    char ***set;
    sfSprite *bg_sprite;
    sfTexture *bg_texture;
    sfRenderWindow *window;
    int area_opacity;
    int item_opacity;
} states_s;
typedef struct timers {
    sfClock *clock;
    sfTime time;
    float seconds;
} my_timer_t;
int is_str_equal(char *str, char *str1);
sfRectangleShape *create_rectangle(sfVector2f position, float size);
sfRenderWindow *window_create(int width, int height, int bPP, int framerate);
planes_t **create_planes(states_s *states);
tower_t **create_tower(states_s *states);
void display_planes(states_s *states,
    planes_t **planes, tower_t **tower, my_timer_t *timer);
void display_towers(states_s *states, tower_t **tower, int nb);
sfVector2f get_velocity(sfVector2f *start, sfVector2f *finish);
double get_angle(sfVector2f *velocity);
int check(int argc, char **argv);
int print_help(void);
void cleanup(planes_t **planes, int nb);
void cleanup_t(tower_t **tower, int nb);
void events(planes_t **planes, states_s *states, sfEvent evt);
void manage_events(planes_t **planes, states_s *states);
float get_y(planes_t *plane);
planes_t *setup_plane(int nb, char **str);
tower_t *setup_tower(float scale, int nb, char **str);
planes_t *setup_plane_invalid(int nb);
tower_t *setup_tower_invalid(float scale, int nb);
void timer(states_s *states, my_timer_t *clock);
char *my_number_to_str(int nb);
int my_nb_digits(long long int nb);
char *my_revstr(char *str);
double get_distance(planes_t *plane, tower_t *tower);
void cleanup_one_plane(planes_t *planes);
void my_str_to_array(states_s *states, char sep);
char *my_strdup(char *src);
int my_strlen(const char *str);
void count(states_s *states);
char *my_strcat(char *dest, char const *src);
int my_getnbr(char const *str);
void fileread(char *filepath, states_s *states);
void draw_remaining(states_s *states, int remain);
int in_tower_zone(planes_t *plane, tower_t **tower);
void manage_opacity(planes_t *planes, states_s *states);
void my_mansion_to_array(states_s *states, char sep, int i);
#endif
