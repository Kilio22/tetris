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
    struct game_props_s game;

    (void)argc;
    (void)argv;
    init_game(&game);
    debug_mode(&game);

    return (0);
}
