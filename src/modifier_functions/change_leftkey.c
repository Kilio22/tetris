/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** change_leftkey
*/

#include "my.h"
#include "tetris.h"

int change_leftkey(struct game_props_s *game, char *arg)
{
    if (!arg || !*arg)
        return print_help("./tetris"), -1;
    free(game->keys[LEFT]);
    game->keys[LEFT] = my_strdup(arg);
    if (!game->keys[LEFT])
        return -1;
    return 0;
}
