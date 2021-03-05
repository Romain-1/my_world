/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** slidebar destroy
*/

#include <slidebar.h>

void slidebar_destroy(slidebar_t *slide_bar)
{
    sfSprite_destroy(slide_bar->background);
    sfSprite_destroy(slide_bar->slide_bar);
}
