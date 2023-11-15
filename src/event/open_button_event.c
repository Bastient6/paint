/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** event_on_open_button_event
*/

#include "../../include/paint.h"

char **get_file_name(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *file;
    char **file_name = malloc(sizeof(char *) * 100);
    int i = 0;

    while ((file = readdir(dir)) != NULL) {
        if (file->d_name[0] != '.') {
            file_name[i] = malloc(sizeof(char) * 100);
            file_name[i] = file->d_name;
            i++;
        }
    }
    file_name[i] = NULL;
    return (file_name);
}

void free_old_button(paint_t *paint)
{
    t_gui_options *tmp = paint->drop_open_button->options;
    while(tmp != NULL) {
        t_gui_options *tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2;
    }
    paint->drop_open_button->options = NULL;
}

t_gui_drop_menu *set_button_on_open(char **files, paint_t *paint)
{
    if (paint->drop_open_button->options != NULL)
        free_old_button(paint);
    for (int i = 0; files[i] != NULL; i++) {
        add_option_drop_menu(paint->drop_open_button, files[i], 10 + i);
    }
    t_gui_options *tmp = paint->drop_open_button->options;
    while (tmp != NULL) {
        sfText_setCharacterSize(tmp->option->text, 17);
        sfVector2f pos = sfRectangleShape_getPosition(tmp->option->rect);
        sfText_setPosition(tmp->option->text, (sfVector2f){pos.x + 7, pos.y + 7});
        tmp = tmp->next;
    }
}

void event_on_open_button_event(paint_t *paint)
{
    char **files = get_file_name("./src/save_file");
    if (files == NULL)
        return;
    set_button_on_open(files, paint);
}
