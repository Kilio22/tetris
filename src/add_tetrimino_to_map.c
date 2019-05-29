/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** add_tetrimino_to_map
*/

#include "tetris.h"

static void reinit_map(struct game_props_s *game, int i)
{
    for (size_t j = 0; j < game->size[1]; j++) {
        if (game->map[i][j].id == 2)
            game->map[i][j].id = 1;
    }
}

static int add_line(struct game_props_s *game, size_t i, int x, int nb_tetri)
{
    bool stared = false;

    for (size_t j = 0; game->tetriminos[nb_tetri]->piece[0][i][j]
!= '\0'; j++, x++) {
        if (game->map[i][x].id != 0)
            return -1;
        game->map[i][x].c = game->tetriminos[nb_tetri]->piece[0][i][j];
        game->map[i][x].color = game->tetriminos[nb_tetri]->color;
        if (game->tetriminos[nb_tetri]->piece[0][i][j] == '*')
            stared = true;
        if (stared == true)
            game->map[i][x].id = 2;
        else {
            game->map[i][x].id = 0;
        }
    }
    return 0;
}

int add_new_tetrimino(struct game_props_s *game)
{
    int nb_tetri = 0;
    int x = 0;

    nb_tetri = get_next_tetriminos(false, game);
    get_next_tetriminos(true, game);
    for (size_t i = 0; game->map[i]; i++)
        reinit_map(game, i);
    x = (game->size[1] - game->tetriminos[nb_tetri]->width) / 2;
    for (size_t i = 0; game->tetriminos[nb_tetri]->piece[0][i]; i++) {
        if (add_line(game, i, x, nb_tetri) == -1)
            return -1;
    }
    return 1;
}