/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** windows_managment
*/

#include "tetris.h"

int create_windows(struct game_props_s *game)
{
    game->win[SCORE] = subwin(stdscr, 10, 40, 40, 0);
    game->win[GAME] = subwin(stdscr, game->size[0], game->size[1], 0, 50);
    if (!game->win[SCORE] || !game->win[GAME])
        return -1;
    wborder(game->win[SCORE], '|', '|', '-', '-', '/', '\\', '\\', '/');
    wborder(game->win[GAME], '|', '|', '-', '-', '+', '+', '+', '+');
    if (!game->next) {
        game->win[NEXT] = subwin(stdscr, 10, 20, 0, game->size[0] + 2 + 50);
        if (!game->win[NEXT])
            return -1;
        wborder(game->win[NEXT], '|', '|', '-', '-', '/', '\\', '\\', '/');
    }
    for (int i = 0; i < NB_WINDOW; i++)
        wrefresh(game->win[i]);
    return 0;
}

void update_windows(struct game_props_s *game)
{
    for (int i = 0; i < NB_WINDOW; i++)
        wclear(game->win[i]);
    wborder(game->win[SCORE], '|', '|', '-', '-', '/', '\\', '\\', '/');
    print_score_board(game->win[SCORE], game);
    wborder(game->win[GAME], '|', '|', '-', '-', '+', '+', '+', '+');
    if (!game->next) {
        wborder(game->win[NEXT], '|', '|', '-', '-', '/', '\\', '\\', '/');
        print_next(game->win[NEXT], game);
    }
    for (int i = 0; i < NB_WINDOW; i++)
        wrefresh(game->win[i]);
}
