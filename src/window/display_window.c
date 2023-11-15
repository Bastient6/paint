/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** display_window
*/

#include "../../include/paint.h"

void display_window(paint_t *paint)
{
    sfRenderWindow_clear(paint->window, sfWhite);
    display_pencil(paint);
    sfRenderWindow_drawRectangleShape(paint->window, paint->overlay[0], NULL);
    sfRenderWindow_drawRectangleShape
    (paint->window, paint->color_window_delim, NULL);
    if (paint->event->mouseMove.x > 200 ){
        sfRenderWindow_setMouseCursorVisible(paint->window, sfFalse);
        sfRenderWindow_drawRectangleShape
        (paint->window, paint->recmousse, NULL);
    } else {
        sfRenderWindow_setMouseCursorVisible(paint->window, sfTrue);
    }
    sfRectangleShape_setSize(paint->recmousse, (sfVector2f){paint->draw->vertex_size * 2, paint->draw->vertex_size * 2});
    sfRectangleShape_setOrigin(paint->recmousse, (sfVector2f){paint->draw->vertex_size, paint->draw->vertex_size});
    sfRectangleShape_setPosition(paint->recmousse, (sfVector2f){paint->event->mouseMove.x, paint->event->mouseMove.y});
    sfRectangleShape_setFillColor(paint->recmousse, sfTransparent);
    sfRectangleShape_setOutlineColor(paint->recmousse, paint->color);
    for (int i = 1; paint->overlay[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape
                (paint->window, paint->overlay[i], NULL);
    }
    display_drop_down_button(paint, paint->drop_file_button);
    display_drop_down_button(paint, paint->drop_edit_button);
    display_drop_down_button(paint, paint->drop_help_button);
    if (paint->display_open_file == 1) {
        display_drop_down_button(paint, paint->drop_open_button);
        //analyse_file_open_hover(paint, paint->drop_open_button);
    }
    sfRenderWindow_drawSprite(paint->window, paint->pipette, NULL);
    sfRenderWindow_drawSprite(paint->window, paint->pinceau, NULL);
    sfRenderWindow_drawSprite(paint->window, paint->gomme, NULL);
    sfRenderWindow_drawSprite(paint->window, paint->palette, NULL);
    sfRenderWindow_drawCircleShape(paint->window, paint->palettecircle, NULL);
    sfRenderWindow_display(paint->window);
}
