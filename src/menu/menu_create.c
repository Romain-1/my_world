/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** menu create
*/

#include <menu.h>

static void button_tools_create(menu_scrolling_t *menu, sfTexture *texture)
{
    sfVector2f pos_scale[2];
    int j = 0;

    pos_scale[0].x = POS_SCALE_TOOLS[0].x;
    pos_scale[0].y = POS_SCALE_TOOLS[0].y;
    pos_scale[1].x = POS_SCALE_TOOLS[1].x;
    pos_scale[1].y = POS_SCALE_TOOLS[1].y;
    menu->button_tools = malloc(sizeof(button_t *) * (NB_TOOLS_BUTTON + 1));
    for (int i = 0; i < NB_TOOLS_BUTTON; i++, j += 2) {
        menu->button_tools[i] = button_create
        (texture, &TEXTURE_POSITION_BUTTON[j],
            BUTTON_FUNCTION_TAB[i], pos_scale);
        pos_scale[0].x += X_TOOLS_BUTTON_SPACE;
        if ((i == 2) || (i == 5) || i == 8 || i == 11) {
            pos_scale[0].y += Y_TOOLS_BUTTON_SPACE;
            pos_scale[0].x = POS_SCALE_TOOLS[0].x;
        }
    }
    menu->button_tools[NB_TOOLS_BUTTON] = NULL;
}

static void menu_set_main_button(menu_scrolling_t *menu, sfTexture *texture)
{
    menu->slide_bar = NULL;
    menu->txt_box = NULL;
    menu->shape = shape_create(TOOLS_SHAPE_POSITION, TOOLS_SHAPE_SCALE);
    menu->main_button = button_create
        (texture, TEXTURE_POSITION_TOOLS_BUTTON,
        (void *)&menu_on_off, POS_SCALE_TOOLS_BUTTON);
    button_tools_create(menu, texture);
}

static void menu_set_save_tools(menu_scrolling_t *menu, sfTexture *texture)
{
    menu->slide_bar = NULL;
    menu->button_tools = malloc(sizeof(button_t *) * 3);
    menu->txt_box = txt_box_create
    ("resources/box.png", POS_SCALE_SAVE_TXT_BOX, SPRITE_RECT_SAVE_TXT_BOX);
    menu->txt_box->is_only_nb = 0;
    menu->txt_box->limit_char = 18;
    menu->main_button = button_create
    (texture, TEXTURE_POSITION_SAVE_MENU,
    (void *)&menu_on_off, POS_SCALE_SAVE_MENU);
    menu->button_tools[0] = button_create
    (texture, TEXTURE_POSITION_SAVE_BUTTON,
    BUTTON_FUNCTION_SAVE[0], POS_SCALE_SAVE_BUTTON);
    menu->button_tools[1] = button_create
    (texture, TEXTURE_POSITION_LOAD_BUTTON,
    BUTTON_FUNCTION_SAVE[1], POS_SCALE_LOAD_BUTTON);
    menu->button_tools[2] = NULL;
    menu->shape = shape_create(SAVE_SHAPE_POSITION, SAVE_SHAPE_SCALE);
}

void menu_set_option_button(menu_scrolling_t *menu, sfTexture *menu_texture)
{
    menu->button_on_off = 0;
    menu->txt_box = NULL;
    menu->main_button = button_create
        (menu_texture, TEXTURE_POSITION_OPTION_MENU,
        (void *)&menu_on_off, POS_SCALE_OPTION_MENU);
    menu->shape = shape_create(OPTION_SHAPE_POSITION, OPTION_SHAPE_SCALE);
    menu->button_tools = malloc(sizeof(button_t) * 4);
    menu->button_tools[0] = button_create
        (menu_texture, TEXTURE_POSITION_SOUND_BUTTON,
        (void *)&slidebar_setvolume_s, POS_SCALE_SOUND_BUTTON);
    menu->button_tools[1] = button_create
        (menu_texture, TEXTURE_POSITION_MUSIC_BUTTON,
        (void *)&slidebar_setvolume_m, POS_SCALE_MUSIC_BUTTON);
    menu->button_tools[2] = button_create
        (menu_texture, TEXTURE_POSITION_LOAD_BUTTON,
        (void *)&world_quit, POS_SCALE_QUIT_BUTTON);
    menu->button_tools[3] = NULL;
    menu->slide_bar = slidebar_create
        (menu_texture, POS_SCALE_SLIDEBAR);
}

menu_t *menu_create(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfTexture *menu_texture = sfTexture_createFromFile
                                            ("resources/sprite.png", NULL);

    if (!menu)
        return (NULL);
    menu->tools_menu = malloc(sizeof(menu_scrolling_t));
    menu->save_menu = malloc(sizeof(menu_scrolling_t));
    menu->sound_menu = malloc(sizeof(menu_scrolling_t));
    menu->tools_menu->button_on_off = 0;
    menu->save_menu->button_on_off = 0;
    menu_set_main_button(menu->tools_menu, menu_texture);
    menu_set_save_tools(menu->save_menu, menu_texture);
    menu_set_option_button(menu->sound_menu, menu_texture);
    menu->map_size = menu_size_map_create(menu_texture);
    return (menu);
}
