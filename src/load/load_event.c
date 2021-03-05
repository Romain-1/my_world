/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** load_event
*/

#include <saved.h>

int load_event(sfRenderWindow *window, saved_t *saves)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (button_on_click(window, event, saves->button_new_map, NULL))
            return (1);
        switch (event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(window);
            break;
        default:
            break;
        }
    }
    return (0);
}
