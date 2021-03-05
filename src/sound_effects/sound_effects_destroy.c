/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** sound_effects_destroy
*/

#include <sound.h>
#include <stdlib.h>

void sound_effects_destroy(sound_t *sound_effects)
{
    if (sound_effects->music) {
        sfMusic_stop(sound_effects->music);
        sfMusic_destroy(sound_effects->music);
    }
    if (sound_effects->sound[PLACED])
        sfSound_destroy(sound_effects->sound[PLACED]);
    if (sound_effects->buffer[PLACED])
        sfSoundBuffer_destroy(sound_effects->buffer[PLACED]);
    if (sound_effects->sound[CLICK])
        sfSound_destroy(sound_effects->sound[CLICK]);
    if (sound_effects->buffer[CLICK])
        sfSoundBuffer_destroy(sound_effects->buffer[CLICK]);
    free(sound_effects);
}
