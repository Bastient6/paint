/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** app_main_loop
*/

#include "../../include/paint.h"

int app_main_loop(paint_t *paint)
{
    float divx = 0;
    float divy = 0;
    paint->draw->vertex_size = 5;
    while (sfRenderWindow_isOpen(paint->window)) {
        while (sfRenderWindow_pollEvent(paint->window, paint->event)) {
            analyse_events(paint);
        }
        add_vertex_to_list(paint);
        display_window(paint);
    }
    sfRenderWindow_destroy(paint->window);
    return 0;
}
