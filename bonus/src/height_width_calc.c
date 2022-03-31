/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-andreas.le-tanter
** File description:
** height_width_calc
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int detect_nb_cols_superior(int nb_cols, int temp)
{
    if (temp < nb_cols)
        temp = nb_cols;
    return (temp);
}

int get_nb_cols(char *map)
{
    int nb_cols = 0;
    int i = 0;
    int temp = 0;

    while (map[i]) {
        if (map[i] == '\n') {
            nb_cols++;
            temp = detect_nb_cols_superior(nb_cols, temp);
            nb_cols = 0;
        }
        nb_cols++;
        i++;
    }
    return (nb_cols);
}

int get_nb_rows(char *map)
{
    int i = 0;
    int nb_rows = 0;

    while (map[i] != '\0') {
        if (map[i] == '\n') {
            nb_rows++;
        }
        i++;
    }
    nb_rows++;
    return (nb_rows);
}
