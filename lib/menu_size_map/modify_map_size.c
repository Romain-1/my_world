/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** modify map size
*/

#include <world.h>

void down_x(void *w)
{
    world_t *world = w;

    if (world->menu->map_size->size.x > 1) {
        world->menu->map_size->txt_box_left->buffer = my_int_to_array
            (my_atoi(world->menu->map_size->txt_box_left->buffer) - 1);
        world->menu->map_size->size.x -= 1;
        world->menu->map_size->new_map_size_function(w);
    }
}

void down_y(void *w)
{
    world_t *world = w;

    if (world->menu->map_size->size.y > 1) {
        world->menu->map_size->txt_box_right->buffer = my_int_to_array
            (my_atoi(world->menu->map_size->txt_box_right->buffer) - 1);
        world->menu->map_size->size.y -= 1;
        world->menu->map_size->new_map_size_function(w);
    }
}

void up_x(void *w)
{
    world_t *world = w;

    if (world->menu->map_size->size.x > 1) {
        world->menu->map_size->txt_box_left->buffer = my_int_to_array
            (my_atoi(world->menu->map_size->txt_box_left->buffer) + 1);
        world->menu->map_size->size.x += 1;
        world->menu->map_size->new_map_size_function(w);
    }
}

void up_y(void *w)
{
    world_t *world = w;

    if (world->menu->map_size->size.y > 1) {
        world->menu->map_size->txt_box_right->buffer = my_int_to_array
            (my_atoi(world->menu->map_size->txt_box_right->buffer) + 1);
        world->menu->map_size->size.y += 1;
        world->menu->map_size->new_map_size_function(w);
    }
}
