/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** check_full_piece
*/

#include "tetris.h"

int check_lines_piece(struct game_props_s *game, int i)
{
    for (size_t j = 0; j < game->size[1]; j++) {
        if (game->map[i][j].id != 2)
            continue;
        if (game->map[i + 1][j].id == 1)
            return add_new_tetrimino(game);
    }
    return 0;
}

int my_find_char_inmap(struct map_s **map, int i,
struct game_props_s *game, char c)
{
    for (size_t j = 0; j < game->size[1]; j++)
        if (map[i][j].c == c && map[i][j].id == 2)
            return j;
    return -1;
}

int check_full_piece(struct game_props_s *game)
{
    int i = 0;
    int n_return = 0;

    for (i = game->size[0] - 1; i >= 0; i--)
        if (my_find_char_inmap(game->map, i, game, '*') != -1)
            break;
    for (; i >= 0 && my_find_char_inmap(game->map, i, game, '*') != -1; i--) {
        if (i == (int) game->size[0] - 1)
            return add_new_tetrimino(game);
        else
            n_return = check_lines_piece(game, i);
        if (n_return == -1)
            return -1;
    }
    return 0;
}