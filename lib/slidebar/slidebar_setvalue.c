/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** slidebar set value
*/

#include <world.h>
#include <menu.h>

void slidebar_getvalue_m(slidebar_t *slide_bar)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(slide_bar->slide_bar);

    slide_bar->volume_m = (100 * bounds.width)
                            / (POSITION_TEXTURE_SLIDE_BAR.width * 0.17);
    if (slide_bar->volume_m > 100)
        slide_bar->volume_m = 100;
}

void slidebar_getvalue_s(slidebar_t *slide_bar)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(slide_bar->slide_bar);

    slide_bar->volume_s = (100 * bounds.width)
                            / (POSITION_TEXTURE_SLIDE_BAR.width * 0.17);
    if (slide_bar->volume_s > 100)
        slide_bar->volume_s = 100;
}

void slidebar_setvolume_s(void *w)
{
    world_t *world = w;

    if (world->menu->sound_menu->slide_bar->volume_s > 0)
        world->menu->sound_menu->slide_bar->volume_s = 0;
    else
        world->menu->sound_menu->slide_bar->volume_s = 100;
}

void slidebar_setvolume_m(void *w)
{
    world_t *world = w;

    if (world->menu->sound_menu->slide_bar->volume_m > 0)
        world->menu->sound_menu->slide_bar->volume_m = 0;
    else
        world->menu->sound_menu->slide_bar->volume_m = 100;
}
