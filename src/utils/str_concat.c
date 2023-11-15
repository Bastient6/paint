/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-thomas.janiaut
** File description:
** str_concat
*/

#include "../../include/paint.h"

char *str_concat(char *str1, char *str2)
{
    char *str = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    int i = 0;
    int j = 0;

    for (; str1[i] != '\0'; i++)
        str[i] = str1[i];
    for (; str2[j] != '\0'; j++) {
        str[i] = str2[j];
        i++;
    }
    str[i] = '\0';
    return (str);
}
