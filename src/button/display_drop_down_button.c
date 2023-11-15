/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** display_drop_down_button
*/

#include "../../include/paint.h"

int check_if_one_hover(paint_t *paint, t_gui_drop_menu *menu)
{
    if (menu->button->is_hover
    (menu->button, &paint->event->mouseMove, paint->window)) {
        return 1;
    }
    t_gui_options *tmp = menu->options;
    while (tmp != NULL) {
        if (tmp->option->is_hover
        (tmp->option, &paint->event->mouseMove, paint->window)) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

void display_drop_down_button(paint_t *paint, t_gui_drop_menu *menu)
{
    sfRenderWindow_drawRectangleShape
    (paint->window, menu->button->rect, NULL);
    sfRenderWindow_drawText(paint->window, menu->button->text, NULL);
    if (IS_PRESSED(menu->button) ||
    (check_if_one_hover(paint, menu) && menu->is_open == 1)) {
        menu->is_open = 1;
        for (t_gui_options *tmp = menu->options; tmp != NULL; tmp = tmp->next) {
            sfRenderWindow_drawRectangleShape
                    (paint->window, tmp->option->rect, NULL);
            sfRenderWindow_drawText(paint->window, tmp->option->text, NULL);
        }
    } else {
        menu->is_open = 0;
    }
}

void display_drop_open_button(paint_t *paint, t_gui_drop_menu *menu)
{
    sfRenderWindow_drawRectangleShape
            (paint->window, menu->button->rect, NULL);
    sfRenderWindow_drawText(paint->window, menu->button->text, NULL);
    if (IS_PRESSED(menu->button) ||
        (check_if_one_hover(paint, menu) && menu->is_open == 1)) {
        menu->is_open = 1;
        for (t_gui_options *tmp = menu->options; tmp != NULL; tmp = tmp->next) {
            sfRenderWindow_drawRectangleShape
                    (paint->window, tmp->option->rect, NULL);
            sfRenderWindow_drawText(paint->window, tmp->option->text, NULL);
        }
    } else {
        menu->is_open = 0;
    }
}