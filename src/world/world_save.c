/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** world_save
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <my_libc.h>
#include <world.h>
#include <unistd.h>

static void file_write_map(int fd, map_t *map)
{
    my_puts(fd, "Lines: ");
    my_putnbr(fd, map->size.y);
    my_puts(fd, " Columns: ");
    my_putnbr(fd, map->size.x);
    write(fd, "\n", 1);
    for (size_t i = 0; i <= map->size.y; i++) {
        for (size_t j = 0; j <= map->size.x; j++) {
            my_putfloat(fd, map->map_2d[i][j]);
            write(fd, " ", 1);
        }
        write(fd, "\n", 1);
    }
}

void world_save(void *w)
{
    world_t *world = w;
    char *save = my_strdup(world->menu->save_menu->txt_box->buffer);
    char *filepath = my_strcat("resources/saves/", save);
    char *screenshot = my_strcat("resources/screenshots/", save);
    int fd = open(filepath, O_WRONLY);

    if (fd == -1)
        fd = open(filepath, O_CREAT | O_WRONLY, 777);
    screenshot = my_strcat(screenshot, ".png");
    world_screenshot(world, screenshot);
    my_puts(fd, "Preview: ");
    my_puts(fd, screenshot);
    my_puts(fd, "\nSeed: ");
    my_putnbr(fd, world->map->seed);
    write(fd, "\n", 1);
    file_write_map(fd, world->map);
    close(fd);
}
