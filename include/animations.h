/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** animations_h
*/

#ifndef _ANIMATIONS_H_
#define _ANIMATIONS_H_

enum animation {PERLIN, RESET, HOLE, WATER_DROP, TWISTED, VALLEY, SWAPPING};

void animation_reset(void *);
void animation_perlin(void *);
void animation_hole(void *);
void animation_water_drop(void *);
void animation_twisted(void *);
void animation_valley(void *);
void animation_swapping(void *);
void animation_screenshot(void *);
void world_change_textures(void *);
void world_change_colors(void *);
void world_change_water(void *);

#endif /* _ANIMATIONS_H_ */
