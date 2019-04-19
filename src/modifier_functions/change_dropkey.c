/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** change_dropkey
*/

#include "my.h"
#include "tetris.h"

int change_dropkey(struct game_props_s *game, char *arg)
{
    if (!arg)
        return -1;
    free(game->keys[DROP]);
    game->keys[DROP] = my_strdup(arg);
    if (!game->keys[DROP])
        return -1;
    return 0;
}
