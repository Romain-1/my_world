/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** button is hold
*/

#include <button.h>

int button_is_hold(sfVector2i position_m, sfFloatRect bounds_s)
{
    if (position_m.x >= bounds_s.left
        && position_m.x <= bounds_s.width + bounds_s.left
        && position_m.y >= bounds_s.top
        && position_m.y <= bounds_s.height + bounds_s.top)
        return (1);
    return (0);
}
