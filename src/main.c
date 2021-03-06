/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include <time.h>
#include "my.h"
#include "tetris.h"
#include "my_string.h"

static int destroy_game(struct game_props_s *game)
{
    write_highscore(game);
    for (int i = 0; i < NB_WINDOW; i++)
        delwin(game->win[i]);
    endwin();
    for (int i = 0; game->tetriminos[i]; i++) {
        free(game->tetriminos[i]->name);
        free(game->tetriminos[i]);
    }
    return 0;
}

static void first_init(void)
{
    initscr();
    my_set_term(0);
    curs_set(0);
    start_color();
    for (int i = 1; i <= 255; i++)
        init_pair(i, i, 0);
}

static int game_launcher(struct game_props_s *game)
{
    int n_return = 0;

    first_init();
    if (game->debug == false)
        n_return = menu();
    if (n_return > 0) {
        my_set_term(1);
        endwin();
        return 84;
    }
    if (setup_game(game) == -1)
        return -1;
    game_loop(game);
    my_set_term(1);
    destroy_game(game);
    return 0;
}

int main(int argc, char *argv[], char **env)
{
    struct game_props_s game;
    int n_return;

    if (display_help(argc, argv))
        return 0;
    srand(time(NULL));
    init_game(&game, env);
    if (modify_game_props(argc, argv, &game) == 84)
        return print_help(argv[0]), 84;
    if (load_tetriminos(&game) == 84)
        return print_help(argv[0]), 84;
    if (game.debug == true)
        debug_mode(&game);
    if (game_launcher(&game) == -1)
        n_return = 84;
    return n_return;
}
