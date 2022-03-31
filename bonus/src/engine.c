/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-andreas.le-tanter
** File description:
** engine
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int centered_redimensioning(char **array, char *map)
{
    char *error_str = "Please enlarge the terminal";

    if (LINES < get_nb_rows(map) || COLS < get_nb_cols(map)) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - my_strlen(error_str) / 2, error_str);
        refresh();
        return (1);
    }
    return (0);
}

void reset_level(char **two_d_array, char **saved_map, char *map)
{
    free(two_d_array);
    two_d_array = mem_alloc_2d_array(map);
    engine(two_d_array, map, saved_map);
}

void init_window(void)
{
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
}

void engine(char **two_d_array, char *map, char **saved_map)
{
    int key = 0;
    init_window();
    while (1) {
        if (centered_redimensioning(two_d_array, map) == 0) {
            clear();
            display_map(two_d_array, map);
            check_for_win(two_d_array, map, saved_map);
            check_for_lose(two_d_array, map, saved_map);
            refresh();
            key = getch();
            two_d_array = move_player(two_d_array, key, map);
            two_d_array = check_for_storage(saved_map, two_d_array, map);
        }
        if (key == ' ') {
            reset_level(two_d_array, saved_map, map);
        }
    }
    endwin();
}
