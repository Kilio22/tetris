/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"

static struct game_props_s init_tetris(int argc, char *argv[])
{
    struct game_props_s 
}

struct game_props_s create_tetris_config(int argc, char *argv[])
{

}

int main(int argc, char *argv[])
{
    int optindex;
    int n_getopt;
    struct game_props_s tetris = default_tetris;

    n_getopt = getopt_long(argc, argv, "L:l:r:t:d:q:p:wD", optlist, &optindex);
    while (n_getopt != -1) {
        printf("%d[%c]\n", n_getopt, n_getopt);
        n_getopt = getopt(argc, argv, "lu");
    }
    return (0);
}
