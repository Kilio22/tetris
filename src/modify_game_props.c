/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** parse_arguments
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_stdio.h"
#include "tetris.h"

static int change_opt(int opt, struct game_props_s *game)
{
    for (int i = 0; args[i].change; i++) {
        if (opt == args[i].opt)
            return args[i].change(game, optarg);
    }
    return 0;
}

int modify_game_props(int argc, char *argv[], struct game_props_s *game)
{
    int optindex;
    int opt;

    opt = getopt_long(argc, argv, "L:l:r:t:d:q:p:wD", optlist, &optindex);
    while (opt != -1) {
        if (change_opt(opt, game) == -1)
            return -1;
        opt = getopt_long(argc, argv, "L:l:r:t:d:q:p:wD", optlist, &optindex);
    }
    return 0;
}
