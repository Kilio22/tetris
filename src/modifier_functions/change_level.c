/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** change_level
*/

#include "my.h"
#include "tetris.h"

int change_level(struct game_props_s *game, char *arg)
{
    if (!arg)
        return -1;
    if (!my_str_isnum(arg, 0))
        return -1;
    game->level = my_atoi(arg);
    if (!game->level)
        return -1;
    return 0;
}
