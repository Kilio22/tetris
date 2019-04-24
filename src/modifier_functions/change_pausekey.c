/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** change_pausekey
*/

#include "my.h"
#include "tetris.h"

int change_pausekey(struct game_props_s *game, char *arg)
{
    if (!arg || !*arg)
        return print_help("./tetris"), -1;
    free(game->keys[PAUSE]);
    game->keys[PAUSE] = my_strdup(arg);
    if (!game->keys[PAUSE])
        return -1;
    return 0;
}
