/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** change_debug
*/

#include "my.h"
#include "tetris.h"

int change_debug(struct game_props_s *game, char *arg)
{
    (void) arg;
    game->debug = true;
    return 0;
}
