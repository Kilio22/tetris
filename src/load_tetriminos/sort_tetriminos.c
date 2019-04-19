/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** sort_tetriminos
*/

#include "tetris.h"

static int is_sorted(struct tetrimino_s **tetrimino)
{
    for (size_t i = 0; tetrimino[i + 1]; i++)
        if (my_strcmp(tetrimino[i]->name, tetrimino[i + 1]->name) > 0)
            return -1;
    return 0;
}

void sorter_tetriminos(struct tetrimino_s **tetriminos)
{
    struct tetrimino_s *tmp;

    for (size_t i = 0; tetriminos[i + 1]; i++) {
        if (my_strcmp(tetriminos[i]->name, tetriminos[i + 1]->name) > 0) {
            tmp = tetriminos[i];
            tetriminos[i] = tetriminos[i + 1];
            tetriminos[i + 1] = tmp;
        }
    }
}

void sort_tetriminos(struct tetrimino_s **tetriminos)
{
    while (is_sorted(tetriminos))
        sorter_tetriminos(tetriminos);
}