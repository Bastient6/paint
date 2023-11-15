/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-bastien.tiffy
** File description:
** my_strlen
*/

#include "../../include/paint.h"
int my_strlen(char *str)
{
    int i = 0;
    for (; str[i] != 0; i++);
    return i;
}
