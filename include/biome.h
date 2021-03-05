/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** biome_h
*/

#ifndef _BIOME_H_
#define _BIOME_H_

typedef struct biome_s {
    float upper_factor;
    float lower_factor;
    float ground_height;
    float resolution;
    char *biome;
} biome_t;

biome_t *biome_create(char const *);

#endif /* _BIOME_H_ */
