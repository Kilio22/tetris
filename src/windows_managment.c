/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** windows_managment
*/

#include "tetris.h"

int create_windows(struct game_props_s *game)
{
    game->win[SCORE] = subwin(stdscr, 10, 40, LINES - 11, 0);
    game->win[GAME] = subwin(stdscr, game->size[0] + 2,
game->size[1] + 2, LINES - game->size[0] - 2, 47);
    if (!game->win[SCORE] || !game->win[GAME])
        return -1;
    wborder(game->win[SCORE], '|', '|', '-', '-', '/', '\\', '\\', '/');
    wborder(game->win[GAME], '|', '|', '-', '-', '+', '+', '+', '+');
    if (!game->next) {
        game->win[NEXT] = subwin(stdscr, 10, 20, LINES - 11,
game->size[1] + 4 + 50);
        if (!game->win[NEXT])
            return -1;
        wborder(game->win[NEXT], '|', '|', '-', '-', '/', '\\', '\\', '/');
    }
    for (int i = 0; i < NB_WINDOW; i++)
        wrefresh(game->win[i]);
    return 0;
}

void position_updates(struct game_props_s *game)
{
    for (int i = 0; i < NB_WINDOW; i++)
        delwin(game->win[i]);
    game->win[SCORE] = subwin(stdscr, 10, 40, LINES - 11, 0);
    game->win[GAME] = subwin(stdscr, game->size[0] + 2,
game->size[1] + 2, LINES - game->size[0] - 2, 47);
    game->win[NEXT] = subwin(stdscr, 10, 20, LINES - 11,
game->size[1] + 4 + 50);
    for (int i = 0; i < NB_WINDOW; i++)
        wclear(game->win[i]);
}

void update_windows(struct game_props_s *game)
{
    clear();
    position_updates(game);
    print_ascii_art(game);
    wborder(game->win[SCORE], '|', '|', '-', '-', '/', '\\', '\\', '/');
    print_score_board(game->win[SCORE], game);
    wborder(game->win[GAME], '|', '|', '-', '-', '+', '+', '+', '+');
    print_game_board(game->win[GAME], game);
    if (!game->next) {
        wborder(game->win[NEXT], '|', '|', '-', '-', '/', '\\', '\\', '/');
        print_next(game->win[NEXT], game);
    }
    refresh();
    for (int i = 0; i < NB_WINDOW; i++)
        wrefresh(game->win[i]);
}
