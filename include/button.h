/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** button header
*/

#ifndef BUTTON_H_
#define BUTTON_H_

/* include needed to be functionnal */

#ifndef STDLIB_H_
#define STDLIB_H_

#include <stdlib.h>

#endif /* STDLIB_H_ */

#ifndef CSFML_INC_H_
#define CSFML_INC_H_

#include <csfml_inc.h>

#endif /* CSFML_INC_H_ */

#include <stdbool.h>

/* structure of the button */

typedef struct button_s {
    sfSprite *button_s;
    sfTexture *button_texture;
    sfIntRect button_on_hold;
    sfIntRect button_idle;
    sfVector2f scale;
    sfVector2f position;
    void (*function)(void *);
    sfText *description;
    int is_holded;
} button_t;

/* function prototypes */
void button_destroy(button_t *);
sfText *create_text(sfColor, unsigned int, sfVector2f, char const *);
void button_draw(sfRenderWindow *, button_t *);
int button_is_hold(sfVector2i, sfFloatRect);
bool button_on_click(sfRenderWindow *, sfEvent, button_t *, void *);
void button_on_hold(sfRenderWindow *, button_t *);
button_t *button_create(sfTexture *, sfIntRect const *,
    void (*)(void *), sfVector2f const *);

#endif /* BUTTON_H_ */
