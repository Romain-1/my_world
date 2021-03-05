/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** world_h
*/

#ifndef _WORLD_H_
#define _WORLD_H_

#include <menu.h>
#include <map.h>
#include <fps.h>
#include <biome.h>
#include <sound.h>

typedef struct world_s {
    int animations;
    fps_t *fps;
    map_t *map;
    menu_t *menu;
    sfView *view_map;
    sfView *view_ui;
    biome_t *biome;
    sound_t *sound_effects;
    sfCircleShape *corner;
    sfRenderWindow *window;
} world_t;

static const size_t WIDTH = 1900;
static const size_t HEIGHT = 1000;

void help(char const *);
void quit_game(void *);
int world_loop(char const *);
void world_draw(world_t *);
void world_events(world_t **);
world_t *world_create(char const *);
void world_screenshot(world_t *, char const *);
void world_save(void *);
void animation_redirect(world_t *);
void world_destroy(world_t *);

#endif /* _WORLD_H_ */
