/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** move_right
*/

#include "tetris.h"

static int get_max_right(struct game_props_s *game, int i)
{
    int pos = my_find_char_inmap_rev(game->map, i, game, '*');
    int tmp = 0;

    for (; game->map[i] && tmp != -1; i++) {
        tmp = my_find_char_inmap_rev(game->map, i, game, '*');
        if (tmp == -1)
            continue;
        if (tmp < (int)game->size[1] - 1 && game->map[i][tmp + 1].id != 0)
            return -1;
        if (tmp > pos)
            pos = tmp;
    }
    return pos;
}

static void apply_move(int i, struct game_props_s *game)
{
    for (int j = game->size[1] - 1; j >= 0; j--) {
        if (game->map[i][j].c == '*' && game->map[i][j].id == 2 && j + 1 < (int) game->size[1]) {
            game->map[i][j].c = ' ';
            game->map[i][j].id = 0;
            game->map[i][j + 1].id = 2;
            game->map[i][j + 1].c = '*';
            game->map[i][j + 1].color = game->map[i][j].color;
        }
    }
}

void move_right(struct game_props_s *game)
{
    int i = 0;
    int max_right = 0;

    for (int i = 0; game->map[i]; i++) {
        if (my_find_char_inmap_rev(game->map, i, game, '*') == -1)
            continue;
        max_right = get_max_right(game, i);
        break;
    }
    if (max_right < 0 || max_right == (int)game->size[1] - 1)
        return;
    for (; game->map[i] &&
my_find_char_inmap(game->map, i, game, '*') == -1; i++);
    for (; game->map[i] &&
my_find_char_inmap(game->map, i, game, '*') != -1; i++)
        apply_move(i, game);
}