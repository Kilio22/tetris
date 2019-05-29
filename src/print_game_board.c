/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** print_game_board
*/

#include "tetris.h"

void print_game_board(WINDOW *win, struct game_props_s *game)
{
    int x = 1;
    int y = 1;

    for (int i = 0; game->map[i]; i++) {
        for (size_t j = 0; j < game->size[1]; j++, x++) {
            wattron(win, COLOR_PAIR(game->map[i][j].color));
            mvwprintw(win, y, x, "%c", game->map[i][j].c);
            wattroff(win, COLOR_PAIR(game->map[i][j].color));
        }
        x = 1;
        y++;
    }
}