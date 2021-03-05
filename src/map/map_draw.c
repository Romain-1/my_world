/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_draw
*/

#include <map.h>
#include <SFML/Graphics.h>

static void display1(sfRenderWindow *win, map_t *map)
{
    sfRenderWindow_drawConvexShape(win, map->ground[4], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[1], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[2], NULL);
    for (size_t i = 0; i < map->size.y; i++)
        for (size_t j = 0; j < map->size.x; j++)
            if (map->map_2d[i][j] <= -1)
                sfRenderWindow_drawConvexShape(win, map->convexes[i][j], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[0], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[3], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[4], NULL);
    for (size_t i = 0; i < map->size.y; i++)
        for (size_t j = 0; j < map->size.x; j++) {
            if (map->map_2d[i][j] > -1)
                sfRenderWindow_drawConvexShape(win, map->convexes[i][j], NULL);
        }
    sfRenderWindow_drawConvexShape(win, map->ground[2], NULL);
    sfRenderWindow_drawConvexShape(win, map->ground[3], NULL);
}

static void display2(sfRenderWindow *win, map_t *map)
{
    sfRenderWindow_drawConvexShape(win, map->ground[4], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[2], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[3], NULL);
    for (int i = map->size.y - 1; i >= 0; i--)
        for (size_t j = 0; j < map->size.x; j++)
            if (map->map_2d[i][j] <= -1)
                sfRenderWindow_drawConvexShape(win, map->convexes[i][j], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[0], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[1], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[4], NULL);
    for (int i = map->size.y - 1; i >= 0; i--)
        for (size_t j = 0; j < map->size.x; j++)
            if (map->map_2d[i][j] > -1)
                sfRenderWindow_drawConvexShape(win, map->convexes[i][j], NULL);
    sfRenderWindow_drawConvexShape(win, map->ground[3], NULL);
    sfRenderWindow_drawConvexShape(win, map->ground[0], NULL);
}

static void display3(sfRenderWindow *win, map_t *map)
{
    sfRenderWindow_drawConvexShape(win, map->ground[4], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[3], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[4], NULL);
    for (int i = map->size.y - 1; i >= 0; i--)
        for (int j = map->size.x - 1; j >= 0; j--)
            if (map->map_2d[i][j] <= -1)
                sfRenderWindow_drawConvexShape(win, map->convexes[i][j], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[0], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[1], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[2], NULL);
    for (int i = map->size.y - 1; i >= 0; i--)
        for (int j = map->size.x - 1; j >= 0; j--)
            if (map->map_2d[i][j] > -1)
                sfRenderWindow_drawConvexShape(win, map->convexes[i][j], NULL);
    sfRenderWindow_drawConvexShape(win, map->ground[0], NULL);
    sfRenderWindow_drawConvexShape(win, map->ground[1], NULL);
}

static void display4(sfRenderWindow *win, map_t *map)
{
    sfRenderWindow_drawConvexShape(win, map->ground[4], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[4], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[1], NULL);
    for (size_t i = 0; i < map->size.y; i++)
        for (int j = map->size.x - 1; j >= 0; j--)
            if (map->map_2d[i][j] <= -1)
                sfRenderWindow_drawConvexShape(win, map->convexes[i][j], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[0], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[2], NULL);
    sfRenderWindow_drawConvexShape(win, map->water[3], NULL);
    for (size_t i = 0; i < map->size.y; i++)
        for (int j = map->size.x - 1; j >= 0; j--)
            if (map->map_2d[i][j] > -1)
                sfRenderWindow_drawConvexShape(win, map->convexes[i][j], NULL);
    sfRenderWindow_drawConvexShape(win, map->ground[1], NULL);
    sfRenderWindow_drawConvexShape(win, map->ground[2], NULL);
}

void map_draw(sfRenderWindow *win, map_t *map)
{
    sfVector2f angle = {acos(map->matrix->array[0][0]) * 180.0 / M_PI,
                        asin(map->matrix->array[1][0]) * 180.0 / M_PI};

    if (map->is_modified = true) {
        map_modify(map);
        map->is_modified = false;
    }
    if (angle.x < 45.0f && angle.y > -45.0f)
        return (display1(win, map));
    if (angle.x > 45.0f && angle.y > 45.0f)
        return (display2(win, map));
    if (angle.x > 135.0f && angle.y < 45.0f)
        return (display3(win, map));
    if (angle.x < 135.0f && angle.y < -45.0f)
        return (display4(win, map));
    display1(win, map);
}
