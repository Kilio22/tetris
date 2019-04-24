/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** change_turnkey
*/

#include "my.h"
#include "tetris.h"

int change_turnkey(struct game_props_s *game, char *arg)
{
    if (!arg || !*arg || *arg == '=')
        return print_help("./tetris"), -1;
    free(game->keys[TURN]);
    game->keys[TURN] = my_strdup(arg);
    if (!game->keys[TURN])
        return -1;
    return 0;
}
