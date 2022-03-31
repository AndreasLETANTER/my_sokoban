/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-andreas.le-tanter
** File description:
** seek_player
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int get_coord_player(char *map, char **array, int i)
{
    for (int j = 0; j <= get_nb_cols(map); j++) {
        if (array[i][j] == 'P') {
            return (1);
        }
    }
    return (-1);
}

int get_j_coord_player(char *map, char **array, int i)
{
    for (int j = 0; j <= get_nb_cols(map); j++) {
        if (array[i][j] == 'P') {
            return (j);
        }
    }
    return (-1);
}

int seek_x_coord_player(char **array, char *map)
{
    for (int i = 0; i < get_nb_rows(map); i++) {
        if (get_coord_player(map, array, i) != -1) {
            return (i);
        }
    }
}

int seek_y_coord_player(char **array, char *map)
{
    for (int i = 0; i < get_nb_rows(map); i++) {
        if (get_j_coord_player(map, array, i) != -1) {
            return (get_j_coord_player(map, array, i));
        }
    }
}
