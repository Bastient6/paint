/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** new_window
*/

#include "../../include/paint.h"

void new_window(paint_t *paint)
{
    sfVideoMode mode = {100, 100, 32};
    paint->newwindow = sfRenderWindow_create
    (mode, "My Paint", sfResize | sfClose, NULL);
    init_window(paint);
}
