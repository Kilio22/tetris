/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** change_mapsize
*/

#include <stdio.h>
#include "my.h"
#include "my_string.h"
#include "tetris.h"

int change_mapsize(struct game_props_s *game, char *arg)
{
    char **array;

    if (!arg || !*arg || *arg == '=')
        return print_help("./tetris"), -1;
    array = my_str_towordarray(arg, ",");
    if (!array)
        return -1;
    if (my_strarraylen(array) != 2)
        return -1;
    if (!my_str_isnum(array[0], 0) || !my_str_isnum(array[1], 0))
        return -1;
    game->size[0] = (size_t) my_atoi(array[0]);
    game->size[1] = (size_t) my_atoi(array[1]);
    if (!game->size[0] || !game->size[1])
        return -1;
    return 0;
}
