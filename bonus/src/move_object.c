/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-andreas.le-tanter
** File description:
** move_object
*/

#include "my.h"

char **move_object_up(int x_player, int y_player, char **array)
{
    if (x_player - 2 == 0)
        return (array);
    if (array[x_player - 1][y_player] == 'X' && array[x_player - 2]
    [y_player] != '#' && array[x_player - 2][y_player] != 'X') {
        array[x_player][y_player] = ' ';
        array[x_player - 1][y_player] = 'P';
        array[x_player - 2][y_player] = 'X';
    }
    return (array);
}

int count_object(char **array, int i, int j, int nb_objects)
{
    if (array[i][j] == 'X') {
        nb_objects++;
    }
    return (nb_objects);
}

char **move_object_down(int x_player, int y_player, char **array)
{
    if (x_player + 3 == get_nb_rows_of_two_d_array(array)) {
        return (array);
    }
    if (array[x_player + 1][y_player] == 'X' && array[x_player + 2]
    [y_player] != '#' && array[x_player + 2][y_player] != 'X') {
        array[x_player][y_player] = ' ';
        array[x_player + 1][y_player] = 'P';
        array[x_player + 2][y_player] = 'X';
    }
    return (array);
}

char **move_object_left(int x_player, int y_player, char **array)
{
    if (array[x_player][y_player - 2] == '\0') {
        return (array);
    }
    if (array[x_player][y_player - 1] == 'X' && array[x_player]
    [y_player - 2] != '#' && array[x_player][y_player - 2] != 'X') {
        array[x_player][y_player] = ' ';
        array[x_player][y_player - 1] = 'P';
        array[x_player][y_player - 2] = 'X';
    }
    return (array);
}

char **move_object_right(int x_player, int y_player, char **array)
{
    if (array[x_player][y_player + 2] == '\0')
        return (array);
    if (array[x_player][y_player + 1] == 'X' && array[x_player]
    [y_player + 2] != '#' && array[x_player][y_player + 2] != 'X') {
        array[x_player][y_player] = ' ';
        array[x_player][y_player + 1] = 'P';
        array[x_player][y_player + 2] = 'X';
    }
    return (array);
}
