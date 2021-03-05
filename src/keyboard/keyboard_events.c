/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** keyboard_events
*/

#include <world.h>

static void animation2_events(world_t *world, sfEvent event)
{
    switch (event.key.code) {
    case sfKeyW:
        animation_water_drop(world);
        break;
    case sfKeyT:
        animation_twisted(world);
        break;
    case sfKeyV:
        animation_valley(world);
        break;
    case sfKeyS:
        animation_swapping(world);
        break;
    default:
        break;
    }
}

static void animation1_events(world_t *world, sfEvent event)
{
    switch (event.key.code) {
    case sfKeySpace:
        animation_perlin(world);
        break;
    case sfKeyReturn:
        animation_reset(world);
        break;
    case sfKeyH:
        animation_hole(world);
        break;
    default:
        animation2_events(world, event);
        break;
    }
}

void keyboard_events(world_t *world, sfEvent event)
{
    switch (event.key.code) {
    case sfKeyP:
        world->map->selection_size += 2;
        break;
    case sfKeyM:
        world->map->selection_size -= 2;
        break;
    case sfKeyF2:
        world_screenshot(world, "resources/screenshots/screenshot.png");
        break;
    default:
        animation1_events(world, event);
        break;
    }
}
