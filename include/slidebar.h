/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** slidebar header
*/

#ifndef SLIDEBAR_H_
#define SLIDEBAR_H_

#ifndef STDLIB_H_
#define STDLIB_H_

#include <stdlib.h>

#endif /* STDLIB_H_ */

#ifndef CSFML_INC_H_
#define CSFML_INC_H_

#include <csfml_inc.h>

#endif /* CSFML_INC_H_ */

typedef struct slidebar_s {
    sfSprite *background;
    sfSprite *slide_bar;
    sfSprite *button;
    int volume_s;
    int volume_m;
} slidebar_t;

void slidebar_destroy(slidebar_t *slide_bar);
slidebar_t *slidebar_create(sfTexture const *, sfVector2f const *);
void slidebar_event(sfRenderWindow *, slidebar_t *);
int button_is_hold(sfVector2i , sfFloatRect );
void slidebar_display(sfRenderWindow *, slidebar_t *);
void slidebar_getvalue_m(slidebar_t *);
void slidebar_getvalue_s(slidebar_t *);

static const sfIntRect POSITION_TEXTURE_BG = {0, 330, 1000, 50};
static const sfIntRect POSITION_TEXTURE_SLIDE_BAR = {0, 290, 890, 40};

#endif /* SLIDEBAR_H_ */
