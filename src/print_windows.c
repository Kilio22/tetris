/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** print_windows
*/

#include "tetris.h"

void print_next(WINDOW *win, struct game_props_s *game)
{
    int i = 0;
    int y = 1;

    mvwprintw(win, 0, 2, "next");
    while (game->tetriminos[i] && !game->tetriminos[i]->valid)
        ++i;
    if (i == game->nb_tetriminos)
        return;
    while (1) {
        i = rand() % game->nb_tetriminos;
        if (game->tetriminos[i]->valid)
            break;
    }
    for (size_t j = 0; game->tetriminos[i]->piece[0][j]; j++)
        mvwprintw(win, y++, 1, "%s", game->tetriminos[i]->piece[0][j]);
}

void print_score_board(WINDOW *win, struct game_props_s *game)
{
    mvwprintw(win, 2, 1, "High Score\t\t 0");
    mvwprintw(win, 3, 1, "Score\t\t\t %d", game->score);
    mvwprintw(win, 4, 1, "Level\t\t\t %d", game->level);
}
