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

    if (display_help(argc, argv))
        return 0;
    init_game(&game);
    if (modify_game_props(argc, argv, &game) == 84)
        return 84;
    load_tetriminos(&game);
    if (game.debug == true)
        debug_mode(&game);
    return (0);
}
