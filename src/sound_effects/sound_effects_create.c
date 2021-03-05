/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** sound_effects_create
*/

#include <world.h>
#include <sound.h>

static void buffers_create(sound_t *sounds)
{
    sounds->buffer[PLACED] = sfSoundBuffer_createFromFile
        ("resources/sounds/modif.ogg");
    sounds->buffer[CLICK] = sfSoundBuffer_createFromFile
        ("resources/sounds/click.ogg");
}

static void music_create(sound_t *sound_effect)
{
    sound_effect->music = sfMusic_createFromFile
        ("resources/music/c418-biom-fest.ogg");
    if (sound_effect->music)
        sfMusic_setLoop(sound_effect->music, sfTrue);
}

sound_t *sound_effects_create(void)
{
    sound_t *sound_effect = malloc(sizeof(sound_t));

    if (!sound_effect)
        return (NULL);
    music_create(sound_effect);
    sound_effect->sound[PLACED] = sfSound_create();
    sound_effect->sound[CLICK] = sfSound_create();
    buffers_create(sound_effect);
    sfSound_setBuffer(sound_effect->sound[PLACED],
                        sound_effect->buffer[PLACED]);
    sfSound_setBuffer(sound_effect->sound[CLICK], sound_effect->buffer[CLICK]);
    sfSound_setVolume(sound_effect->sound[PLACED], 50);
    sfSound_setVolume(sound_effect->sound[CLICK], 50);
    return (sound_effect);
}
