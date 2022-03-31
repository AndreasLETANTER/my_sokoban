/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-andreas.le-tanter
** File description:
** main
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void free_array(char **array, char *map)
{
    int nb_rows = get_nb_rows(map);

    for (int i = 0; i < nb_rows; i++) {
        free(array[i]);
    }
    free(array);
}

int main(int argc, char **argv)
{
    char *map;
    char **two_d_array;
    char **saved_map;

    if (argc != 2) {
        return (84);
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        display_help();
    } else {
        map = get_map(argv[1]);
        two_d_array = mem_alloc_2d_array(map);
        saved_map = mem_alloc_2d_array(map);
        engine(two_d_array, map, saved_map);
        free_array(two_d_array, map);
        free_array(saved_map, map);
    }
    free(map);
}
