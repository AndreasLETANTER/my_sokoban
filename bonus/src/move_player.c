/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-andreas.le-tanter
** File description:
** move_player
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

char **move_player_up(int key, int x_player, int y_player, char **array)
{
    if (key == KEY_UP) {
        if (x_player == 0 || array[x_player - 1][y_player] == '#') {
            return (array);
        }
        array = move_object_up(x_player, y_player, array);
        if (array[x_player - 1][y_player] != 'X') {
            array[x_player][y_player] = ' ';
            array[x_player - 1][y_player] = 'P';
        }
    }
    return (array);
}

char **move_player_down(int key, int x_player, int y_player, char **array)
{
    if (key == KEY_DOWN) {
        if (x_player + 2 == get_nb_rows_of_two_d_array(array)
        || array[x_player + 1][y_player] == '#') {
            return (array);
        }
        array = move_object_down(x_player, y_player, array);
        if (array[x_player + 1][y_player] != 'X') {
            array[x_player][y_player] = ' ';
            array[x_player + 1][y_player] = 'P';
        }
    }
    return (array);
}

char **move_player_right(int key, int x_player, int y_player, char **array)
{
    if (key == KEY_RIGHT) {
        if (array[x_player][y_player + 1] == '#'
        || array[x_player][y_player + 2] == '\0') {
            return (array);
        }
        array = move_object_right(x_player, y_player, array);
        if (array[x_player][y_player + 1] != 'X') {
            array[x_player][y_player] = ' ';
            array[x_player][y_player + 1] = 'P';
        }
    }
    return (array);
}

char **move_player_left(int key, int x_player, int y_player, char **array)
{
    if (key == KEY_LEFT) {
        if (array[x_player][y_player - 1] == '#') {
            return (array);
        }
        array = move_object_left(x_player, y_player, array);
        if (array[x_player][y_player - 1] != 'X') {
            array[x_player][y_player] = ' ';
            array[x_player][y_player - 1] = 'P';
        }
    }
    return (array);
}

char **move_player(char **array, int key, char *map)
{
    int x_player = seek_x_coord_player(array, map);
    int y_player = seek_y_coord_player(array, map);

    array = move_player_up(key, x_player, y_player, array);
    array = move_player_down(key, x_player, y_player, array);
    array = move_player_left(key, x_player, y_player, array);
    array = move_player_right(key, x_player, y_player, array);
    return (array);
}
