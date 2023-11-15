/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** event_zoom
*/

#include "../../include/paint.h"

void event_zoom(paint_t *paint)
{
    if (paint->event->type == sfEvtMouseWheelScrolled) {
        if (paint->event->mouseWheelScroll.delta > 0) {
            paint->zoom += 0.1;
        } else {
            paint->zoom -= 0.1;
        }
    }
}
