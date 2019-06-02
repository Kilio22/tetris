/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** highscore_managment
*/

#include "tetris.h"

void write_highscore(struct game_props_s *game)
{
    int fd = open(".highscore", O_CREAT | O_RDWR, 0664);

    if (fd == -1)
        return;
    if (game->highscore > game->score)
        return;
    my_dprintf(fd, "%d\n", game->score);
    close(fd);
}