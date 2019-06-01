/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** rotate_piece
*/

#include "tetris.h"

int rotate_current_piece(struct game_props_s *game)
{
    if (++game->rotation > 3)
        game->rotation = 0;
    return 0;
}
