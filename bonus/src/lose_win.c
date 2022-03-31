/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-andreas.le-tanter
** File description:
** lose_win
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

int seek_objects(char **array, char **saved_map, int nb_cols, int i)
{
    for (int j = 0; j <= nb_cols; j++) {
        if (saved_map[i][j] == 'O' && array[i][j] != 'X') {
            return (1);
        }
    }
    return (0);
}

int check_for_win(char **array, char *map, char **saved_map)
{
    int nb_rows = get_nb_rows(map);
    int nb_cols = get_nb_cols(map);

    for (int i = 0; i < nb_rows; i++) {
        if (seek_objects(array, saved_map, nb_cols, i) == 1) {
            return (1);
        }
    }
    free_array(array, map);
    free_array(saved_map, map);
    free(map);
    endwin();
    exit(0);
}

void my_exit_lose(char **array, char *map, char **saved_map)
{
    free_array(array, map);
    free_array(saved_map, map);
    free(map);
    endwin();
    exit(1);
}

int reduce_object(char **array, int i, int j, int nb_objects)
{
    if (array[i][j] == 'X' && ((array[i + 1]
    [j] == '#')) && (array[i][j + 1] == '#')) {
        nb_objects--;
        return (nb_objects);
    } else if (array[i][j] == 'X' && ((array[i - 1]
    [j] == '#')) && (array[i][j - 1] == '#')) {
        nb_objects--;
        return (nb_objects);
    }
    if (array[i][j] == 'X' && ((array[i]
    [j + 1] == '#')) && (array[i - 1][j] == '#')) {
        nb_objects--;
        return (nb_objects);
    } else if (array[i][j] == 'X' && ((array[i]
    [j - 1] == '#')) && (array[i + 1][j] == '#')) {
        nb_objects--;
        return (nb_objects);
    }
    return (nb_objects);
}

int check_for_lose(char **array, char *map, char **saved_map)
{
    int nb_rows = get_nb_rows(map);
    int nb_cols = get_nb_cols(map);
    int nb_objects = 0;
    int objects = 0;

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j <= nb_cols; j++) {
            objects = count_object(array, i, j, objects);
        }
    }
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j <= nb_cols; j++) {
            nb_objects = count_object(array, i, j, nb_objects);
            nb_objects = reduce_object(array, i, j, nb_objects);
        }
    }
    if (nb_objects == 0) {
        my_exit_lose(array, map, saved_map);
    }
}
