/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-andreas.le-tanter
** File description:
** two_d_array
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int get_nb_rows_of_two_d_array(char **array)
{
    int rows = 0;
    for (int i = 0, p = 0; array[i] != NULL; i++) {
        rows++;
    }
    return (rows);
}

char **initialyze_array(char **my_map, int nb_rows, int nb_cols)
{
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j <= nb_cols; j++) {
            my_map[i][j] = '\0';
        }
    }
    return (my_map);
}

char **mem_alloc_2d_array(char *map)
{
    int nb_rows = get_nb_rows(map);
    int nb_cols = get_nb_cols(map);
    char **two_d_array = malloc(sizeof(char *) * nb_rows + 1);
    int i = 0;

    for (; i < nb_rows; i++) {
        two_d_array[i] = malloc(sizeof(char) * nb_cols + 1);
    }
    two_d_array = initialyze_array(two_d_array, nb_rows, nb_cols);
    for (int x = 0, j = 0, p = 0; map[x]; x++, j++) {
        two_d_array[p][j] = map[x];
        if (map[x] == '\n') {
            p++;
            j = 0;
        }
    }
    return (two_d_array);
}

void display_in_terminal(char **array, int i, int j)
{
    if (array[i][j] != '\0') {
        addch(array[i][j]);
    }
}

void display_map(char **array, char *map)
{
    int nb_rows = get_nb_rows(map);
    int nb_cols = get_nb_cols(map);
    int x = 0;
    for (int i = 0; i < nb_rows; i++) {
        move(LINES / 2 + x - nb_rows / 2, COLS / 2 - nb_cols / 2);
        for (int j = 0; j <= nb_cols; j++) {
            display_in_terminal(array, i, j);
        }
        x++;
    }
}
