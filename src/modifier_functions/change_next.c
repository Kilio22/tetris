/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** change_next
*/

#include "my.h"
#include "tetris.h"

int change_next(struct game_props_s *game, char *arg)
{
    (void) arg;
    game->next = true;
    return 0;
}
