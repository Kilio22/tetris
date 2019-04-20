/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** windows_managment
*/

#include "tetris.h"

void create_windows(struct game_props_s *game)
{
    game->win = malloc(sizeof(WINDOW *) * 3);
    game->win[0] = subwin(stdscr, 10, 40, 40, 0);
    game->win[1] = subwin(stdscr, 10, 20, 0, game->size[0] + 2 + 50);
    game->win[2] = subwin(stdscr, game->size[0], game->size[1], 0, 50);
    wborder(game->win[0], '|', '|', '-', '-', '/', '\\', '\\', '/');
    wborder(game->win[1], '|', '|', '-', '-', '/', '\\', '\\', '/');
    wborder(game->win[2], '|', '|', '-', '-', '+', '+', '+', '+');
    for (int i = 0; i < 3; i++)
        wrefresh(game->win[i]);
}

void update_windows(struct game_props_s *game)
{
    for (int i = 0; i < 3; i++)
        werase(game->win[i]);
    wborder(game->win[0], '|', '|', '-', '-', '/', '\\', '\\', '/');
    wborder(game->win[1], '|', '|', '-', '-', '/', '\\', '\\', '/');
    wborder(game->win[2], '|', '|', '-', '-', '+', '+', '+', '+');
    print_next(game->win[1], game);
    print_score_board(game->win[0], game);
    for (int i = 0; i < 3; i++)
        wrefresh(game->win[i]);
}