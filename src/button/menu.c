/*
** EPITECH PROJECT, 2023
** bs_mypaint
** File description:
** menu
*/

#include "../../include/paint.h"

t_gui_drop_menu *create_drop_menu
    (sfVector2f position, sfVector2f size, sfColor color, char *text)
{
    t_gui_drop_menu *drop_menu = malloc(sizeof(t_gui_drop_menu));
    drop_menu->button = init_button(position, size, color, text);
    drop_menu->options = NULL;
    drop_menu->is_open = 0;
    return drop_menu;
}

void add_first_menu
(t_gui_drop_menu *drop_menu, char *text, int index, t_gui_options *new_option)
{
    sfVector2f position =
            sfRectangleShape_getPosition(drop_menu->button->rect);
    new_option->option = init_button((sfVector2f){position.x, position.y
    + drop_menu->button->size.y},drop_menu->button->size, sfBlack, text);
    new_option->option->button_index = index;
    new_option->next = NULL;
    drop_menu->options = new_option;
}

t_gui_drop_menu *add_option_drop_menu
(t_gui_drop_menu *drop_menu, char *text, int index)
{
    t_gui_options *new_option = malloc(sizeof(t_gui_options));
    if (drop_menu->options == NULL) {
        add_first_menu(drop_menu, text, index, new_option);
    } else {
        t_gui_options *tmp = drop_menu->options;
        while (tmp->next != NULL)
            tmp = tmp->next;
        sfVector2f position = sfRectangleShape_getPosition(tmp->option->rect);
        new_option->option = init_button((sfVector2f){position.x, position.y
        + tmp->option->size.y}, drop_menu->button->size, sfBlack, text);
        new_option->option->button_index = index;
        new_option->next = NULL;
        tmp->next = new_option;
        tmp->next->next = NULL;
    }
    return drop_menu;
}

void display_drop_menu(t_gui_drop_menu *drop_menu, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, drop_menu->button->rect, NULL);
    for (t_gui_options *tmp = drop_menu->options; tmp != NULL; tmp = tmp->next)
        sfRenderWindow_drawRectangleShape(window, tmp->option->rect, NULL);
}
