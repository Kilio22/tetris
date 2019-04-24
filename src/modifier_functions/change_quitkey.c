/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** change_quitkey
*/

#include "my.h"
#include "tetris.h"

int change_quitkey(struct game_props_s *game, char *arg)
{
    if (!arg || !*arg)
        return print_help("./tetris"), -1;
    free(game->keys[QUIT]);
    game->keys[QUIT] = my_strdup(arg);
    if (!game->keys[QUIT])
        return -1;
    return 0;
}
