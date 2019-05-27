/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** print_ascii_art
*/

#include "tetris.h"

void print_ascii_art(struct game_props_s *game)
{
    int y = 2;
    static int color = 1;

    for (size_t i = 0; game->ascii_art[i]; i++, y++) {
        attron(COLOR_PAIR(color));
        mvprintw(y, COLS - 112, "%s", game->ascii_art[i]);
        attroff(COLOR_PAIR(color));
        color += color < 255 ? 1 : -255;
    }
}