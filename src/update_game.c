/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** update_game
*/

#include "tetris.h"

static void update_tetrimono_pos(struct game_props_s *game, int i, size_t j)
{
    char tmp;

    tmp = game->map[i][j].c;
    game->map[i][j].id = 0;
    game->map[i][j].c = ' ';
    game->map[i + 1][j].color = game->map[i][j].color;
    game->map[i][j].color = 0;
    game->map[i + 1][j].id = 2;
    game->map[i + 1][j].c = tmp;
}

static void update_map(struct game_props_s *game, int i)
{
    for (size_t j = 0; j < game->size[1]; j++) {
        if (game->map[i][j].id == 2)
            update_tetrimono_pos(game, i, j);
    }
}

int update_game(struct game_props_s *game, bool drop)
{
    int n_return = 0;

    n_return = check_full_piece(game);
    if (n_return == -1 || n_return == 1)
        return n_return;
    if (drop) {
        for (int i = game->size[0] - 1; i >= 0; i--)
            update_map(game, i);
    }
    return 0;
}