/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** str_concat
*/

#include "../../include/paint.h"

char *str_concat_with_number(char *str1, char c)
{
    char *str = malloc(sizeof(char) * (my_strlen(str1) + 2));
    int i = 0;

    for (; str1[i] != 0; i++){
        if (str1[i] == ' ')
            str[i] = c;
        else
            str[i] = str1[i];
    }
    return (str);
}
