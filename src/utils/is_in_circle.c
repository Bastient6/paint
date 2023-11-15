/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** is_in_circle
*/

#include "../../include/paint.h"

int is_in_circle(sfMouseButtonEvent *pos, sfCircleShape *circle)
{
    sfVector2f pos_circle = sfCircleShape_getPosition(circle);
    pos_circle.x += sfCircleShape_getRadius(circle);
    pos_circle.y += sfCircleShape_getRadius(circle);
    if (sqrt(pow(pos->x - pos_circle.x, 2) + pow(pos->y - pos_circle.y, 2))
        < sfCircleShape_getRadius(circle)) {
        return (1);
    }
    return (0);
}
