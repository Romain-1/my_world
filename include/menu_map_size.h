/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** menu map size header
*/

#ifndef MENU_MAP_SIZE_H_
#define MENU_MAP_SIZE_H_

#ifndef CSFML_INC_H_
#define CSFML_INC_H_

#include <csfml_inc.h>

#endif /* CSFML_INC_H_ */

#ifndef STDLIB_H_
#define STDLIB_H_

#include <stdlib.h>

#endif /* STDLIB_H_ */

#include <button.h>
#include <txt_box.h>

typedef struct menu_map_size_s {
    button_t *button[4];
    sfText *txt[2];
    sfRectangleShape *shape;
    txt_box_t *txt_box_left;
    txt_box_t *txt_box_right;
    void (*new_map_size_function)(void *);
    char *str[2];
    sfVector2i size;
} menu_map_size_t;

enum button_name {DOWN_LEFT, DOWN_RIGHT, UP_LEFT, UP_RIGHT};
enum side {X, Y};

sfText *create_text(sfColor, unsigned int, sfVector2f, char const *);
menu_map_size_t *menu_size_map_create(sfTexture *texture);
void menu_map_size_display(sfRenderWindow *, menu_map_size_t *);
void up_x(void *);
void up_y(void *);
void down_x(void *);
void down_y(void *);
void menu_map_size_update(menu_map_size_t *);
char *my_int_to_array(int);
int my_atoi(char const *);
void world_modify_size(void *);

static const void (*FUNCTION_RESIZE_MAP)(void *) = NULL;

static const sfVector2f MAP_SIZE_SHAPE_POSITION = {1705, 855};
static const sfVector2f MAP_SIZE_SHAPE_SCALE = {210, 170};

static const sfVector2f TXT_BOX_RIGHT_POS_SCALE[] = {{1830, 865},
                                                    {0.070, 0.22}};
static const sfVector2f TXT_BOX_LEFT_POS_SCALE[] = {{1720, 865},
                                                    {0.070, 0.22}};
static const sfVector2f POSITION_TXT_X = {1720, 915};
static const sfVector2f POSITION_TXT_Y = {1830, 915};
static const sfVector2f POS_SCALE_DOWN_LEFT_BUTTON[2] = {{1750, 955},
                                                        {0.2, 0.2}};
static const sfVector2f POS_SCALE_DOWN_RIGHT_BUTTON[2] = {{1860, 955},
                                                        {0.2, 0.2}};
static const sfVector2f POS_SCALE_UP_LEFT_BUTTON[2] = {{1750, 835},
                                                        {0.2, 0.2}};
static const sfVector2f POS_SCALE_UP_RIGHT_BUTTON[2] = {{1860, 835},
                                                        {0.2, 0.2}};

static const sfIntRect TEXTURE_POSITION_DOWN_LEFT_BUTTON[2] = {{2940, 210,
                                                            210, 210},
                                                            {3150, 210,
                                                            210, 210}};
static const sfIntRect TEXTURE_POSITION_DOWN_RIGHT_BUTTON[2] = {{2940, 210,
                                                            210, 210},
                                                            {3150, 210,
                                                            210, 210}};
static const sfIntRect TEXTURE_POSITION_UP_LEFT_BUTTON[2] = {{2940, 0,
                                                            210, 210},
                                                            {3150, 0,
                                                            210, 210}};
static const sfIntRect TEXTURE_POSITION_UP_RIGHT_BUTTON[2] = {{2940, 0,
                                                            210, 210},
                                                            {3150, 0,
                                                            210, 210}};

#endif /* MENU_MAP_SIZE_H_ */
