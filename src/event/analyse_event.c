/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** analyse_event
*/

#include "../../include/paint.h"

void event_color_picker_tiles(paint_t *paint)
{
    for (int i = 1; paint->overlay[i] != NULL; i++) {
        sfFloatRect rect = sfRectangleShape_getGlobalBounds(paint->overlay[i]);
        if (paint->event->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains
        (&rect, paint->event->mouseButton.x, paint->event->mouseButton.y)) {
            paint->color = sfImage_getPixel(sfRenderWindow_capture
            (paint->window), paint->event->mouseButton.x,
            paint->event->mouseButton.y);
            paint->chose_color_tab = paint->overlay[i];
        }
        sfRectangleShape_setOutlineColor(paint->overlay[i], sfBlack);
        if (paint->chose_color_tab)
            sfRectangleShape_setOutlineColor(paint->chose_color_tab, sfWhite);
    }
}

void event_resize(paint_t *paint)
{
    if ( paint->event->type == sfEvtKeyPressed &&
    paint->event->key.code == sfKeyP)
        if (paint->draw->vertex_size < 150)
            paint->draw->vertex_size += 2;
    if ( paint->event->type == sfEvtKeyPressed &&
    paint->event->key.code == sfKeyM)
        if (paint->draw->vertex_size > 2)
            paint->draw->vertex_size -= 2;
    if (paint->event->type == sfEvtMouseButtonPressed
    && paint->event->mouseButton.x > 20
    && paint->event->mouseButton.y > 300 && paint->event->mouseButton.x < 60
    && paint->event->mouseButton.y < 340 )
        paint->color = sfBlack;
    analyse_event_button(paint, paint->drop_file_button);
    analyse_event_button(paint, paint->drop_edit_button);
    analyse_event_button(paint, paint->drop_help_button);
    analyse_event_button(paint, paint->drop_open_button);
    event_color_picker_tiles(paint);
}

void event_set_color(paint_t *paint)
{
    if (paint->event->type == sfEvtMouseButtonPressed && is_in_circle
    (&paint->event->mouseButton, paint->palettecircle)) {
        paint->color = sfImage_getPixel(sfRenderWindow_capture
                (paint->window), paint->event->mouseButton.x,
                paint->event->mouseButton.y);
        if (paint->chose_color_tab)
            sfRectangleShape_setFillColor(paint->chose_color_tab, paint->color);
    }
    if (paint->event->type == sfEvtMouseButtonPressed
    && paint->event->mouseButton.x > 80
    && paint->event->mouseButton.y > 300 && paint->event->mouseButton.x < 120
    && paint->event->mouseButton.y < 340 )
        paint->color = sfWhite;
}

void event_ctrl_pressed(paint_t *paint)
{
    if (paint->event->type == sfEvtKeyPressed &&
    (paint->event->key.code == sfKeyLControl ||
    paint->event->key.code == sfKeyRControl))
        paint->ctrl = 1;
    if (paint->event->type == sfEvtKeyPressed &&
    paint->event->key.code == sfKeyZ && paint->ctrl == 1)
        undo_function(paint);
    if (paint->event->type == sfEvtKeyPressed &&
    paint->event->key.code == sfKeyY && paint->ctrl == 1)
        redo_function(paint);
    if ( paint->event->type == sfEvtKeyPressed &&
    paint->event->key.code == sfKeyS && paint->ctrl == 1)
        save_function(paint);
    if (paint->event->type == sfEvtKeyReleased &&
    (paint->event->key.code == sfKeyLControl ||
    paint->event->key.code == sfKeyRControl))
        paint->ctrl = 0;
    event_set_color(paint);
    event_resize(paint);
}

void analyse_events(paint_t *paint)
{
    if (paint->event->type == sfEvtClosed)
        sfRenderWindow_close(paint->window);
    if (paint->event->type == sfEvtKeyPressed
    && paint->event->key.code == sfKeyEscape)
        sfRenderWindow_close(paint->window);
    if (paint->event->type == sfEvtMouseButtonPressed &&
    paint->event->mouseButton.button == sfMouseLeft &&
    (sfMouse_getPosition((sfWindow*)paint->window).x > 200)) {
        paint->is_drawing = 1;
        add_new_vertex_to_list(paint);
    }
    if (paint->event->type == sfEvtMouseButtonReleased &&
    paint->event->mouseButton.button == sfMouseLeft)
        paint->is_drawing = 0;
    if (paint->event->type == sfEvtResized)
        sfRenderWindow_setView(paint->window, sfView_createFromRect
        ((sfFloatRect){0, 0, paint->event->size.width,
        paint->event->size.height}));
    event_ctrl_pressed(paint);
}
