/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** open_window
*/

#include "../../include/paint.h"

void open_window(paint_t *paint)
{
    sfVideoMode mode = {1920, 1080, 32};
    paint->event = malloc(sizeof(sfEvent));
    paint->window = sfRenderWindow_create
    (mode, "My Paint", sfResize | sfClose, NULL);
    init_window(paint);
    init_sprite_pinceau(paint);
    init_sprite_gomme(paint);
    init_sprite_palette(paint);
    init_sprite_pipette(paint);
    init_draw(paint);
    paint->vertexList = malloc(sizeof(vertex_list_t));
    paint->vertexList->draw = NULL;
    paint->vertexList->index = -1;
}
