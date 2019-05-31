/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** move_left
*/

#include "tetris.h"

static int get_max_left(struct game_props_s *game, int i)
{
    int pos = my_find_char_inmap(game->map, i, game, '*');
    int tmp = 0;

    for (; game->map[i] && tmp != -1; i++) {
        tmp = my_find_char_inmap(game->map, i, game, '*');
        if (tmp == -1)
            continue;
        if (tmp < pos)
            pos = tmp;
    }
    return pos;
}

static void apply_move(int i, struct game_props_s *game)
{
    for (size_t j = 0; j < game->size[1]; j++) {
        if (game->map[i][j].c == '*' && j > 0) {
            game->map[i][j].c = ' ';
            game->map[i][j].id = 0;
            game->map[i][j - 1].id = 2;
            game->map[i][j - 1].c = '*';
            game->map[i][j - 1].color = game->map[i][j].color;
        }
    }
}

void move_left(struct game_props_s *game)
{
    int i = 0;
    int max_left = 0;

    for (int i = 0; game->map[i]; i++) {
        if (my_find_char_inmap_rev(game->map, i, game, '*') == -1)
            continue;
        max_left = get_max_left(game, i);
        break;
    }
    if (max_left <= 0)
        return;
    for (; game->map[i] &&
my_find_char_inmap(game->map, i, game, '*') == -1; i++);
    for (; game->map[i] &&
my_find_char_inmap(game->map, i, game, '*') != -1; i++)
        apply_move(i, game);
}