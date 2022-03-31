/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-andreas.le-tanter
** File description:
** display_map
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void count_object_in_map(char *map)
{
    int player = 0;
    int object = 0;
    int storage = 0;

    for (int i = 0; map[i]; i++) {
        if (map[i] == 'P')
            player++;
        if (map[i] == 'X')
            storage++;
        if (map[i] == 'O')
            object++;
    }
    if (player != 1 || storage != object || storage == 0) {
        free(map);
        exit(84);
    }
}

void check_error_in_map(char *map)
{
    for (int i = 0; map[i]; i++) {
        if (map[i] != '#' && map[i] != ' ' && map[i] != 'P'
        && map[i] != 'X' && map[i] != 'O' &&
        map[i] != '\0' && map[i] != '\n') {
            free(map);
            exit(84);
        }
    }
    count_object_in_map(map);
}

char *get_map(char *filepath)
{
    struct stat size;
    char *map;
    int open_file = open(filepath, O_RDONLY);

    if (open_file == -1)
        exit(84);
    stat(filepath, &size);
    map = malloc(sizeof(char) * size.st_size + 1);
    map[0] = '\0';
    map[size.st_size] = '\0';
    read(open_file, map, size.st_size);
    if (map[size.st_size] == '\0' && map[size.st_size - 1] == '\n') {
        for (int i = 1; map[size.st_size - i] == '\n'; i++) {
            map[size.st_size - i] = '\0';
        }
    }
    close(open_file);
    check_error_in_map(map);
    return (map);
}
