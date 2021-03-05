/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** sound
*/

#ifndef _SOUND_H_
#define _SOUND_H_

#include <SFML/Audio.h>

typedef struct sound_s {
    sfMusic *music;
    sfSound *sound[3];
    sfSoundBuffer *buffer[3];
} sound_t;

enum sounds {PLACED, CLICK, EXPAND, ANIMATIONS};

sound_t *sound_effects_create(void);
void sound_effects_destroy(sound_t *);

#endif /* _SOUND_H_ */
