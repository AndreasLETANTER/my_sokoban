/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-andreas.le-tanter
** File description:
** display_storage
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

char **seek_storage(char **saved_map, char **map_loaded, int nb_cols, int i)
{
    for (int j = 0; j <= nb_cols; j++) {
        if (saved_map[i][j] == 'O' && map_loaded[i][j] == ' ') {
            map_loaded[i][j] = 'O';
        }
    }
    return (map_loaded);
}

char **check_for_storage(char **saved_map, char **map_loaded, char *map)
{
    int nb_rows = get_nb_rows(map);
    int nb_cols = get_nb_cols(map);

    for (int i = 0; i < nb_rows; i++) {
        map_loaded = seek_storage(saved_map, map_loaded, nb_cols, i);
    }
    return (map_loaded);
}
