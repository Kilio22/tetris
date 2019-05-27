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
        mvwprintw(win, y, x, "%s", game->map[i]);
        y++;
    }
}