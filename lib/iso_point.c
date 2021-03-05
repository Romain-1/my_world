/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** iso_point
*/

#include <math.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Vector3.h>

#define DEG_TO_RAD(nb) (nb * M_PI / 180.0f)

sfVector2f iso_point(sfVector3f pos)
{
    sfVector2f angle = {DEG_TO_RAD(45), DEG_TO_RAD(35)};
    sfVector2f result = {cos(angle.x) * pos.x -
                        cos(angle.x) * pos.y,
                        sin(angle.y) * pos.y +
                        sin(angle.y) * pos.x -
                        pos.z / 2.0f};

    return (result);
}
