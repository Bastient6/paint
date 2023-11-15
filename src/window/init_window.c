/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** init_window
*/

#include "../../include/paint.h"

void init_overlay(paint_t *paint)
{
    paint->overlay[4] = init_rect_outline
            (paint, (sfVector2f){123, 900}, (sfVector2f){30, 30}, BLACK);
    paint->overlay[5] = init_rect_outline
            (paint, (sfVector2f){161, 900}, (sfVector2f){30, 30}, WHITE);
    paint->overlay[6] = NULL;
    paint->color_window_delim = init_rect
            (paint, (sfVector2f){0, 700}, (sfVector2f){200, 400}, DARKEST_GREY);
}

void init_window(paint_t *paint)
{
    paint->windowcolor = sfWhite;
    paint->overlay = malloc(sizeof(sfRectangleShape *) * 12);
    paint->overlay[0] = init_rect
            (paint, (sfVector2f){0, 0}, (sfVector2f){200, 1080}, GREY);
    paint->overlay[1] = init_rect_outline
            (paint, (sfVector2f){9, 900}, (sfVector2f){30, 30}, RED);
    paint->overlay[2] = init_rect_outline
            (paint, (sfVector2f){47, 900}, (sfVector2f){30, 30}, PURPLE);
    paint->overlay[3] = init_rect_outline
            (paint, (sfVector2f){85, 900}, (sfVector2f){30, 30}, BLUE);
    init_overlay(paint);
}
