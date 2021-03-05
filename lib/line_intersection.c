/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** line_intersection
*/

#include <SFML/System/Vector2.h>
#include <stdbool.h>

bool line_intersection(sfVector2f p1, sfVector2f p2,
                        sfVector2f p3, sfVector2f p4)
{
    float den = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);
    float t = 0;
    float u = 0;

    if (!den)
        return (false);
    t = ((p1.x - p3.x) * (p3.y - p4.y) - (p1.y - p3.y) * (p3.x - p4.x)) / den;
    u = -((p1.x - p2.x) * (p1.y - p3.y) - (p1.y - p2.y) * (p1.x - p3.x)) / den;
    if (t >= 0 && t <= 1 && u > 0)
        return (true);
    return (false);
}
