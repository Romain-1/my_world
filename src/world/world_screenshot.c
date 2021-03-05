/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** screenshot
*/

#include <my_libc.h>
#include <world.h>

void world_screenshot(world_t *world, char const *filepath)
{
    sfImage *image = NULL;
    sfVector2u window_size = sfRenderWindow_getSize(world->window);
    sfTexture *texture = sfTexture_create(window_size.x, window_size.y);

    sfRenderWindow_clear(world->window, (sfColor){47, 47, 47, 255});
    sfRenderWindow_setView(world->window, world->view_map);
    map_colors(world->map);
    map_draw(world->window, world->map);
    sfTexture_updateFromRenderWindow(texture, world->window, 0, 0);
    image = sfTexture_copyToImage(texture);
    sfImage_saveToFile(image, filepath);
}
