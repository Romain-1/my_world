/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** world_events
*/

#include <stdbool.h>
#include <mouse.h>
#include <animations.h>
#include <keyboard.h>

static int can_press_key(menu_t *menu)
{
    return (!menu->save_menu->txt_box->txt_box_hold
            && !menu->map_size->txt_box_left->txt_box_hold
            && !menu->map_size->txt_box_right->txt_box_hold);
}

static bool handle_events(world_t **world, sfEvent event)
{
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close((*world)->window);
        break;
    case sfEvtMouseWheelScrolled:
        sfView_zoom((*world)->view_map, ZOOM(event.mouseWheelScroll.delta));
        break;
    case sfEvtKeyPressed:
        if (can_press_key((*world)->menu))
            keyboard_events((*world), event);
        break;
    default:
        return (button_on_click((*world)->window, event,
                                (*world)->menu->save_menu->button_tools[1],
                                world));
    }
    return (false);
}

static bool window_event(world_t **world)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent((*world)->window, &event)) {
        (*world)->menu->button_pressed = false;
        menu_event((*world)->window, (*world)->menu, event, *world);
        if ((*world)->menu->button_pressed)
            sfSound_play((*world)->sound_effects->sound[CLICK]);
        if (handle_events(world, event))
            return (true);
    }
    return (false);
}

static void world_sound_effect(world_t *world)
{
    if (world->sound_effects->music)
        sfMusic_setVolume(world->sound_effects->music,
                            world->menu->sound_menu->slide_bar->volume_m);
    if (world->sound_effects->sound[PLACED])
        sfSound_setVolume(world->sound_effects->sound[PLACED],
                            world->menu->sound_menu->slide_bar->volume_s);
    if (world->sound_effects->sound[CLICK])
        sfSound_setVolume(world->sound_effects->sound[CLICK],
                            world->menu->sound_menu->slide_bar->volume_s);
}

void world_events(world_t **world)
{
    float zoom = 0;

    if (window_event(world))
        return;
    menu_mouse_hover((*world)->window, (*world)->menu);
    if (!(*world)->menu->button_pressed)
        mouse_events(*world);
    animation_redirect(*world);
    if (can_press_key((*world)->menu))
        keyboard_pressed(*world);
    if ((*world)->sound_effects)
        world_sound_effect(*world);
}
