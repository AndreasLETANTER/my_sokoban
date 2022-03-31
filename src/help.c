/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-andreas.le-tanter
** File description:
** help
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int display_help(void)
{
    struct stat size;
    char *help;
    int open_file = open("ressources/help", O_RDONLY);

    stat("ressources/help", &size);
    help = malloc(sizeof(char) * size.st_size + 1);
    help[0] = '\0';
    help[size.st_size] = '\0';
    read(open_file, help, size.st_size);
    close(open_file);
    my_printf("%s\n", help);
    free(help);
    return (0);
}
