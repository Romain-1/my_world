/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** saved_h
*/

#ifndef _SAVED_H_
#define _SAVED_H_

#include <button.h>
#include <SFML/Graphics.h>

typedef struct saved_s {
    sfTexture **textures;
    sfSprite **sprites;
    button_t *button_new_map;
    char **paths;
    unsigned int length;
} saved_t;

saved_t *load_saves(void);
char *load_loop(void);
int load_event(sfRenderWindow *, saved_t *);

static const sfIntRect RECT_POS_BUTTON_CREATE[] = {{0, 0, 1200, 250},
                                                    {0, 0, 1200, 250}};
static const sfVector2f POS_SCALE_BUTTON_CREATE[] = {{1000, 950}, {1, 0.5}};

#endif /* _SAVED_H_ */
