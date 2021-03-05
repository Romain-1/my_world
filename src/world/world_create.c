/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** world_create
*/

#include <my_libc.h>
#include <world.h>

static const sfVideoMode MODE = {WIDTH, HEIGHT, 32};

static sfView *view_create(sfFloatRect rect)
{
    sfView *view = sfView_create();

    sfView_setCenter(view, (sfVector2f){rect.left, rect.top});
    sfView_setSize(view, (sfVector2f){rect.width, rect.height});
    return (view);
}

static sfCircleShape *circle_create(void)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, 5);
    sfCircleShape_setFillColor(circle, sfWhite);
    sfCircleShape_setOrigin(circle, (sfVector2f){5, 5});
    return (circle);
}

static fps_t *fps_settings(void)
{
    fps_t *fps = fps_create();

    if (!fps)
        return (NULL);
    fps_set_position(fps, (sfVector2f){0, 0});
    fps_set_font(fps, "resources/fonts/DS-DIGI.TTF");
    return (fps);
}

static void world_create2(world_t *world, char const *filepath)
{
    sfVector2u size = {20, 20};

    world->map = filepath ? map_load(filepath) :
        map_create((sfVector2i){20, 20});
    if (!world->map)
        return;
    world->corner = circle_create();
    world->animations = 0;
    world->biome = biome_create(NULL);
    world->menu = menu_create();
    world->fps = fps_settings();
    world->window = sfRenderWindow_create(MODE, "my_world",
                                            sfResize | sfClose, NULL);
    world->sound_effects = sound_effects_create();
    size = sfRenderWindow_getSize(world->window);
    sfRenderWindow_setFramerateLimit(world->window, 60);
    world->view_ui = view_create((sfFloatRect){WIDTH / 2, HEIGHT / 2,
                size.x, size.y});
    world->view_map = view_create((sfFloatRect){0, 0, size.x, size.y});
}

world_t *world_create(char const *filepath)
{
    world_t *world = malloc(sizeof(world_t));
    char **word_array = NULL;
    int i = 0;

    if (!world)
        return (NULL);
    world_create2(world, filepath);
    if (!world->map || !world->view_ui || !world->view_map
        || !world->sound_effects || !world->fps || !world->biome
        || !world->menu || !world->corner)
        return (NULL);
    world->menu->map_size->txt_box_left->buffer =
        my_int_to_array(world->map->size.y);
    world->menu->map_size->txt_box_right->buffer =
        my_int_to_array(world->map->size.x);
    word_array = my_str_to_word_array(filepath, "/");
    for (; word_array && word_array[i]; i++);
    if (word_array && i > 0)
        world->menu->save_menu->txt_box->buffer = word_array[i - 1];
    return (world);
}
