/*
** EPITECH PROJECT, 2021
** duplicate_string.c
** File description:
** duplicate_string.c
*/

#include <stdlib.h>
#include "../../include/my.h"

char *duplicate_string(char const *src)
{
    char *new_str = malloc(sizeof(char *) * my_strlen(src));

    for (int i = 0; src[i] != '\0'; i++) {
        new_str[i] = src[i];
    }
    return (new_str);
}
