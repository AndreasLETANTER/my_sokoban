/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-andreas.le-tanter
** File description:
** tests
*/

#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(display_map, exit_code, .exit_code = 0)
{
    get_map("ressources/map");
}

Test(display_map_error, exit_code, .exit_code = 84)
{
    get_map("ressources/maps");
}

Test(display_map_error_2, exit_code, .exit_code = 84)
{
    get_map("ressources/invalid_map");
}

Test(display_help, exit_code, .exit_code = 0)
{
    display_help();
}

Test(display_map_error_3, exit_code, .exit_code = 84)
{
    get_map("ressources/too_many_player_map");
}

Test(display_map_error_4, exit_code, .exit_code = 84)
{
    get_map("ressources/not_enough_player_map");
}

Test(display_map_error_5, exit_code, .exit_code = 84)
{
    get_map("ressources/not_enough_object_map");
}

Test(display_map_error_6, exit_code, .exit_code = 84)
{
    get_map("ressources/not_enough_storage_map");
}

Test(display_map_error_7, exit_code, .exit_code = 84)
{
    get_map("ressources/no_storage_map");
}

Test(display_map_error_8, exit_code, .exit_code = 84)
{
    get_map("ressources/no_object_map");
}

Test(display_map_error_9, exit_code, .exit_code = 84)
{
    get_map("ressources/no_player_map");
}
