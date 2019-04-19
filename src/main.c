/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include "tetris.h"
#include "my_string.h"

int main(int argc, char *argv[])
{
    int optindex;
    int n_getopt;
    struct game_props_s game;

    (void)argc;
    (void)argv;
    init_game(&game);
    n_getopt = getopt_long(argc, argv, "L:l:r:t:d:q:p:wD", optlist, &optindex);
    while (n_getopt != -1) {
        printf("%d[%c]\n", n_getopt, n_getopt);
        n_getopt = getopt(argc, argv, "lu");
    }
    debug_mode(&game);
    return (0);
}
