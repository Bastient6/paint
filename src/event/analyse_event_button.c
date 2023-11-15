/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** analyse_event_button
*/

#include "../../include/paint.h"

void button_mapping_handler(paint_t *paint, t_gui_options *tmp)
{
    if (tmp->option->button_index == 1)
        new_function(paint);
    if (tmp->option->button_index == 2) {
        event_on_open_button_event(paint);
        paint->display_open_file = 1;
    }
    if (tmp->option->button_index == 3)
        save_function(paint);
    if (tmp->option->button_index == 4)
        undo_function(paint);
    if (tmp->option->button_index == 5)
        redo_function(paint);
    if (tmp->option->button_index == 6)
        paint->vertexList->index = -1;
    if (tmp->option->button_index == 7)
        help_function(paint);
}

void analyse_event_button(paint_t *paint, t_gui_drop_menu *menu)
{
    if ( menu->button->is_clicked(menu->button , &paint->event->mouseButton)) {
        menu->is_open = 1;
        sfRectangleShape_setFillColor(menu->button->rect, LIGHT_GREY);
    } else {
        sfRectangleShape_setFillColor(menu->button->rect, menu->button->color);
    }
    for (t_gui_options *tmp = menu->options; tmp != NULL; tmp = tmp->next){
        if (menu->button->is_clicked
        (tmp->option, &paint->event->mouseButton) == 0) {
            sfRectangleShape_setFillColor
            (tmp->option->rect, menu->button->color);
            continue;
        }
        if (menu->is_open)
            button_mapping_handler(paint, tmp);
        sfRectangleShape_setFillColor(tmp->option->rect, LIGHT_GREY);
    }
}

void analyse_file_open_hover(paint_t *paint, t_gui_drop_menu *menu)
{
    int hover = 0;
    if (paint->drop_file_button->options->next->option->is_clicked(paint->drop_file_button->options->next->option, &paint->event->mouseButton) == 1) {
        return;
    }
    if (menu->button->is_hover(menu->button, &paint->event->mouseMove, paint->window) == 1) {
        return;
    }
    for (t_gui_options *tmp = menu->options; tmp != NULL; tmp = tmp->next){
        if (menu->button->is_hover(tmp->option, &paint->event->mouseMove, paint->window) == 1) {
            return;
        }
    }
    paint->display_open_file = 0;
}