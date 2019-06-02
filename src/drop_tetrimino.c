/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** drop_tetrimino
*/

#include "tetris.h"

int drop_tetrimino(struct game_props_s *game)
{
    int n_return = 0;

    while (n_return == 0) {
        n_return = update_game(game, true);
        update_windows(game);
        if (n_return == -1)
            return -1;
        usleep(10000);
    }
    usleep(40000);
    return 0;
}