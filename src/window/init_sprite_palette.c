/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** init_sprite_palette
*/

#include "../../include/paint.h"

void init_sprite_palette(paint_t *paint)
{
    paint->palette = sfSprite_create();
    paint->palettetexture =
            sfTexture_createFromFile("./src/sprite/chromatic.png", NULL);
    sfSprite_setTexture(paint->palette, paint->palettetexture, sfTrue);
    sfSprite_setScale(paint->palette, (sfVector2f){0.08, 0.08});
    sfSprite_setPosition(paint->palette, (sfVector2f){4, 700});

    paint->palettecircle = sfCircleShape_create();
    sfCircleShape_setRadius(paint->palettecircle, 96);
    sfCircleShape_setPosition(paint->palettecircle, (sfVector2f){4, 700});
    sfCircleShape_setFillColor(paint->palettecircle, sfTransparent);
    sfRenderWindow_drawSprite(paint->window, paint->palette, NULL);
}
