/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** load_loop
*/

#include <saved.h>
#include <world.h>
#include <my_libc.h>

static const sfVideoMode MODE = {WIDTH, HEIGHT, 32};

static void display_images(sfRenderWindow *window, saved_t *saves)
{
    int y = 0;
    int x = 0;

    for (int i = 0; saves && i < saves->length; i++) {
        if ((y + 1) * 1080 * 0.2 > 900) {
            x++;
            y = 0;
        }
        sfSprite_setPosition(saves->sprites[i],
                            (sfVector2f){x * 1920 * 0.2, y * 1080 * 0.2});
        sfRenderWindow_drawSprite(window, saves->sprites[i], NULL);
        y++;
    }
    button_draw(window, saves->button_new_map);
}

static int check_click(sfRenderWindow *window, saved_t *saves)
{
    sfVector2i mouse;
    sfFloatRect rect;

    if (!sfMouse_isButtonPressed(sfMouseLeft))
        return (-1);
    mouse = sfMouse_getPositionRenderWindow(window);
    for (int i = 0; saves && i < saves->length; i++) {
        rect = sfSprite_getGlobalBounds(saves->sprites[i]);
        if (mouse.x > rect.left && mouse.y > rect.top
            && mouse.x < rect.left + rect.width
            && mouse.y < rect.top + rect.height)
            return (i);
    }
    return (-1);
}

static void load_display(sfRenderWindow *window, saved_t *saves)
{
    sfRenderWindow_clear(window, sfBlack);
    display_images(window, saves);
    sfRenderWindow_display(window);
}

char *load_loop(void)
{
    sfRenderWindow *window = sfRenderWindow_create(MODE, "my_world",
                                                    sfClose, NULL);
    saved_t *saves = load_saves();
    int i = 0;

    if (!saves) {
        my_puts(2, "Error: missing saves directory\n");
        return (NULL);
    }
    while (sfRenderWindow_isOpen(window)) {
        if (load_event(window, saves))
            return (NULL);
        i = check_click(window, saves);
        load_display(window, saves);
        if (i != -1)
            sfRenderWindow_close(window);
    }
    sfRenderWindow_destroy(window);
    return (i > 0 ? saves->paths[i] : NULL);
}
