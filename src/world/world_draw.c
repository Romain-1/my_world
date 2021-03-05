/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** world_draw
*/

#include <world.h>

void world_draw(world_t *world)
{
    sfRenderWindow_clear(world->window, (sfColor){47, 47, 47, 255});
    sfRenderWindow_setView(world->window, world->view_map);
    map_draw(world->window, world->map);
    if (world->map->selection_size < 1)
        sfRenderWindow_drawCircleShape(world->window, world->corner, NULL);
    sfRenderWindow_setView(world->window, world->view_ui);
    menu_display(world->window, world->menu);
    fps_draw(world->window, world->fps);
    sfRenderWindow_display(world->window);
}
