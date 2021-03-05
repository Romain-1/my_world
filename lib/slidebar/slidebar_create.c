/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** slidebar create
*/

#include <slidebar.h>

static void slidebar_fill_sprite
    (slidebar_t *slide_bar, sfTexture const *texture)
{
    slide_bar->background = sfSprite_create();
    slide_bar->button = sfSprite_create();
    slide_bar->slide_bar = sfSprite_create();
    sfSprite_setTexture(slide_bar->background, texture, sfTrue);
    sfSprite_setTexture(slide_bar->button, texture, sfTrue);
    sfSprite_setTexture(slide_bar->slide_bar, texture, sfTrue);
}

static void slidebar_set_sprite
    (slidebar_t *slide_bar, sfVector2f const *pos_scale)
{
    sfVector2f position;

    position.x = pos_scale[0].x + 3;
    position.y = pos_scale[0].y + 3;
    sfSprite_setTextureRect(slide_bar->background, POSITION_TEXTURE_BG);
    sfSprite_setTextureRect(slide_bar->slide_bar, POSITION_TEXTURE_SLIDE_BAR);
    sfSprite_setPosition(slide_bar->background, pos_scale[0]);
    sfSprite_setPosition(slide_bar->slide_bar, position);
    sfSprite_setScale(slide_bar->background, pos_scale[1]);
    sfSprite_setScale(slide_bar->slide_bar,
        (sfVector2f){pos_scale[1].x + 0.015, pos_scale[1].y});
}

slidebar_t *slidebar_create
    (sfTexture const *texture, sfVector2f const *pos_scale)
{
    slidebar_t *slide_bar = malloc(sizeof(slidebar_t));

    if (!slide_bar)
        return (NULL);
    slide_bar->volume_s = 100;
    slide_bar->volume_m = 100;
    slidebar_fill_sprite(slide_bar, texture);
    slidebar_set_sprite(slide_bar, pos_scale);
    return (slide_bar);
}
