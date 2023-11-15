/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** init_sprite
*/

#include "../../include/paint.h"

void init_sprite_gomme(paint_t *paint)
{
    paint->gomme = sfSprite_create();
    paint->gommetexture =
            sfTexture_createFromFile("./src/sprite/gomme.png", NULL);
    sfSprite_setTexture(paint->gomme, paint->gommetexture, sfTrue);
    sfSprite_setPosition(paint->gomme, (sfVector2f){80, 300});
    sfSprite_setScale(paint->gomme, (sfVector2f){0.1, 0.1});
    sfRenderWindow_drawSprite(paint->window, paint->gomme, NULL);
}
