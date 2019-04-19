/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** change_rightkey
*/

#include "my.h"
#include "tetris.h"

int change_rightkey(struct game_props_s *game, char *arg)
{
    if (!arg)
        return -1;
    free(game->keys[RIGHT]);
    game->keys[RIGHT] = my_strdup(arg);
    if (!game->keys[RIGHT])
        return -1;
    return 0;
}
