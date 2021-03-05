/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** txt_box header
*/

#ifndef TXT_BOX_H_
#define TXT_BOX_H_

#ifndef STDLIB_H_
#define STDLIB_H_

#include <stdlib.h>

#endif /* STDLIB_H_ */

#ifndef CSFML_INC_H_
#define CSFML_INC_H_

#include <csfml_inc.h>

#endif /* CSFML_INC_H_ */

typedef struct txt_box_s {
    sfSprite *txt_box_s;
    sfSprite *cursor;
    sfTexture *texture_txt_box;
    sfTexture *texture_cursor;
    sfClock *cursor_clock;
    sfText *text;
    sfVector2f position;
    sfVector2f scale;
    void (*size_map_function)(void *);
    char *buffer;
    int txt_box_hold;
    int nb_char;
    int limit_char;
    int is_only_nb;
} txt_box_t;

void txt_box_destroy(txt_box_t *txt_box);
sfText *create_text(sfColor, unsigned int, sfVector2f, char const *);
void txt_box_display(sfRenderWindow *, txt_box_t *);
txt_box_t *txt_box_create(char *, sfVector2f const *, sfIntRect const);
void txt_box_manage_event(sfRenderWindow *, sfEvent, txt_box_t *, void *);

#endif /*TXT_BOX_H_ */
