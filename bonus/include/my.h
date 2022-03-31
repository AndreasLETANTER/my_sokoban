/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/
#include <stdarg.h>

#ifndef MY_HEADER_FILE_H
    #define MY_HEADER_FILE_H

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char debug(void);
char *my_strncat(char *dest, char const *src, int nb);
int my_printf(char *str, ...);
int my_convert_octal(int nbr);
int my_convert_hexadecimal(int nbr);
int my_convert_adress(int nbr);
int convert_binary(int nbr);
int analyze_octal_str(char *str);
int analyze_flag(char flag, char *str, int i, va_list list);
int analyze_flag2(char flag, char *str, int i, va_list list);
int analyze_flag3(char flag, char *str, int i, va_list list);
int str_analyzing(char *str, va_list list);
int print_varflag(char flag, va_list list);
int print_varflag2(char flag, va_list list);
int print_varflag3(char flag, va_list list);
int convert_low_hexa(int nbr);
char **split_string(char const *str);
int get_nb_arg(char **path, int i);
char *concat_strings(char *dest, char const *src);
char *duplicate_string(char const *src);
int display_help(void);
char *get_map(char *filepath);
char **mem_alloc_2d_array(char *map);
void display_map(char **array, char *map);
int get_nb_cols(char *map);
int get_nb_rows(char *map);
void engine(char**two_d_array, char *map, char **saved_map);
int seek_y_coord_player(char **array, char *map);
char **move_player_up(int key, int x_player, int y_player, char **array);
char **move_player_down(int key, int x_player, int y_player, char **array);
char **move_player_right(int key, int x_player, int y_player, char **array);
char **move_player_left(int key, int x_player, int y_player, char **array);
char **move_player(char **array, int key, char *map);
int seek_x_coord_player(char **array, char *map);
char **move_object_right(int x_player, int y_player, char **array);
char **move_object_left(int x_player, int y_player, char **array);
char **move_object_up(int x_player, int y_player, char **array);
char **move_object_down(int x_player, int y_player, char **array);
void free_array(char **array, char *map);
int check_for_win(char **array, char *map, char **saved_map);
void my_exit_lose(char **array, char *map, char **saved_map);
int count_object(char **array, int i, int j, int nb_objects);
int check_for_lose(char **array, char *map, char **saved_map);
char **check_for_storage(char **saved_map, char **map_loaded, char *map);
int get_nb_rows_of_two_d_array(char **array);

#endif
