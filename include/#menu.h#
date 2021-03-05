/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** menu header
*/

#ifndef MENU_H_
#define MENU_H_

#ifndef STDLIB_H_
#define STDLIB_H_

#include <stdlib.h>

#endif /* STDLIB_H_ */

#include <csfml_inc.h>
#include <animations.h>
#include <slidebar.h>
#include <button.h>
#include <txt_box.h>
#include <menu_map_size.h>
#include <stdbool.h>

/* DEFINE HERE YOUR PTR FUNCTION FOR TOOLS AND SAVE BUTTONS */

void world_set_select_corner(void *);
void world_set_select_tiles(void *);
void world_quit(void *);
void world_save(void *);
void world_reload(void *);

/* END */

/* MENU STRUCTURE */

typedef struct menu_scrolling_s {
    button_t *main_button;
    button_t **button_tools;
    txt_box_t *txt_box;
    slidebar_t *slide_bar;
    sfRectangleShape *shape;
    int button_on_off;
} menu_scrolling_t;

typedef struct menu_s {
    menu_scrolling_t *tools_menu;
    menu_scrolling_t *save_menu;
    menu_scrolling_t *sound_menu;
    menu_map_size_t *map_size;
    bool button_pressed;
} menu_t;

/* END */

/* MENU FUNCTIONS INCLUDE */
void menu_destroy(menu_t *menu);
sfRectangleShape *shape_create(sfVector2f const, sfVector2f const);
void menu_save_on_off(menu_t *);
void menu_mouse_hover(sfRenderWindow *, menu_t *);
void menu_event(sfRenderWindow *, menu_t *, sfEvent, void *);
void menu_on_off(menu_scrolling_t *);
menu_t *menu_create(void);
void menu_display(sfRenderWindow *, menu_t *);
void slidebar_setvolume_m(void *);
void slidebar_setvolume_s(void *);

/* END */

/* CONSTANT */

/* NB OF TOOLS BUTTONS */
static const size_t NB_TOOLS_BUTTON = 12;

/* POSITION AND SCALE OF THE DIFFERENT BUTTONS */
static const sfVector2f POS_SCALE_TOOLS_BUTTON[2] = {{1700, 100}, {0.5, 0.5}};
static const sfVector2f POS_SCALE_TOOLS[2] = {{1600, 250}, {0.4, 0.4}};
static const sfVector2f POS_SCALE_SAVE_MENU[2] = {{100, 100}, {0.5, 0.5}};
static const sfVector2f POS_SCALE_SAVE_BUTTON[2] = {{600, 90}, {0.4, 0.4}};
static const sfVector2f POS_SCALE_LOAD_BUTTON[2] = {{700, 90}, {0.4, 0.4}};
static const sfVector2f POS_SCALE_SAVE_TXT_BOX[2] = {{190, 55}, {0.3, 0.3}};
static const sfVector2f POS_SCALE_OPTION_MENU[2] = {{50, 950}, {0.3, 0.3}};
static const sfVector2f POS_SCALE_SOUND_BUTTON[2] = {{320, 950}, {0.2, 0.2}};
static const sfVector2f POS_SCALE_MUSIC_BUTTON[2] = {{370, 950}, {0.2, 0.2}};
static const sfVector2f POS_SCALE_SLIDEBAR[2] = {{112, 935}, {0.17, 0.5}};
static const sfVector2f POS_SCALE_QUIT_BUTTON[2] = {{420, 950}, {0.2, 0.2}};

/* POSITION OF THE TEXTURE ON THE SPRITESHEET */
static const sfIntRect TEXTURE_POSITION_TOOLS_BUTTON[2] = {{420, 0,
                                                            210, 210},
                                                            {630, 0,
                                                            210, 210}};
static const sfIntRect TEXTURE_POSITION_SAVE_MENU[2] = {{0, 0, 210, 210},
                                                        {210, 0, 210, 210}};
static const sfIntRect TEXTURE_POSITION_SAVE_BUTTON[2] = {{840, 0,
                                                            210, 210},
                                                            {1050, 0,
                                                            210, 210}};
static const sfIntRect TEXTURE_POSITION_LOAD_BUTTON[2] = {{1260, 0,
                                                            210, 210},
                                                            {1470, 0,
                                                            210, 210}};
static const sfIntRect SPRITE_RECT_SAVE_TXT_BOX = {0, 0, 1196, 254};
static const sfIntRect TEXTURE_POSITION_BUTTON[] = {{0, 475, 210, 210},
                                                    {210, 475, 210, 210},
                                                    {420, 475, 210, 210},
                                                    {630, 475, 210, 210},
                                                    {840, 475, 210, 210},
                                                    {1050, 475, 210, 210},
                                                    {1260, 475, 210, 210},
                                                    {1470, 475, 210, 210},
                                                    {1680, 475, 210, 210},
                                                    {1890, 475, 210, 210},
                                                    {2100, 475, 210, 210},
                                                    {2310, 475, 210, 210},
                                                    {2520, 475, 210, 210},
                                                    {2730, 475, 210, 210},
                                                    {2940, 475, 210, 210},
                                                    {3150, 475, 210, 210},
                                                    {3360, 475, 210, 210},
                                                    {3570, 475, 210, 210},
                                                    {0, 685, 210, 210},
                                                    {210, 685, 210, 210},
                                                    {420, 685, 210, 210},
                                                    {630, 685, 210, 210},
                                                    {840, 685, 210, 210},
                                                    {1050, 685, 210, 210}};
static const sfIntRect TEXTURE_POSITION_OPTION_MENU[2] = {{1680, 0, 210, 210},
                                                        {1890, 0, 210, 210}};
static const sfIntRect TEXTURE_POSITION_SOUND_BUTTON[2] = {{2100, 0, 210, 210},
                                                        {2310, 0, 210, 210}};
static const sfIntRect TEXTURE_POSITION_MUSIC_BUTTON[2] = {{2520, 0, 210, 210},
                                                        {2730, 0, 210, 210}};

/* POSITION AND SCALE OF THE BACKGROUND SHAPE OF THE DIFFERENT MENU */
static const sfVector2f TOOLS_SHAPE_SCALE = {400, 450};
static const sfVector2f TOOLS_SHAPE_POSITION = {1500, 180};
static const sfVector2f SAVE_SHAPE_SCALE = {600, 150};
static const sfVector2f SAVE_SHAPE_POSITION = {170, 25};
static const sfVector2f OPTION_SHAPE_POSITION = {100, 915};
static const sfVector2f OPTION_SHAPE_SCALE = {350, 70};

/* COLOR OF THE BACKGROUND SHAPES */
static const sfColor MENU_BG_COLOR = {50, 50, 50, 150};

/* SPACE BETWEEN TOOLS BUTTONS */
static const int X_TOOLS_BUTTON_SPACE = 100;
static const int Y_TOOLS_BUTTON_SPACE = 100;

/* PATH OF THE DIFFERENT resources */
static const char *TOOLS_BUTTON_TEXTURE[] = {"resources/sprite.png",
                                                "button"};
static const char *TEST[] = {"resources/img.png", "test"};

static const char *BUTTON_TEXT_OVER[] = {"Tools",
                                        "Selection point",
                                        "Selection tiles",
                                        "Screenshot",
                                        "Perlin noise",
                                        "Reset heights",
                                        "Textures",
                                        "Colors",
                                        "Water",
                                        "Water drop",
                                        "Hole",
                                        "Twisted",
                                        "Valley",
                                        "",
                                        "Save",
                                        "Load",
                                        "",
                                        "Sound",
                                        "Music",
                                        "Quit",
                                        "-",
                                        "-",
                                        "+",
                                        "+",
                                        "", NULL};

/* PTR FUNCTION */
static const void (*BUTTON_FUNCTION_TAB[])(void *) = {world_set_select_corner,
                                                        world_set_select_tiles,
                                                        animation_screenshot,
                                                        animation_perlin,
                                                        animation_reset,
                                                        world_change_textures,
                                                        world_change_colors,
                                                        world_change_water,
                                                        animation_water_drop,
                                                        animation_hole,
                                                        animation_twisted,
                                                        animation_valley};
static const void (*BUTTON_FUNCTION_SAVE[2])(void *) = {world_save,
                                                        world_reload};

/* END */

#endif /* MENU_H_ */
