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
    for (int i = 0; i < NB_WINDOW; i++)
        delwin(game->win[i]);
    endwin();
    for (int i = 0; game->tetriminos[i]; i++) {
        free(game->tetriminos[i]->name);
        free(game->tetriminos[i]);
    }
    return 0;
}

static int check_too_small_term(void)
{
    if (COLS < 190 || LINES < 45) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 8, "ENLARGE YOUR TERMINAL");
        refresh();
        return -1;
    }
    return 0;
}

int analyse_keys(struct game_props_s *game, char *line)
{
    if (!my_strcmp(game->keys[QUIT], line))
        return 1;
    if (!my_strcmp(line, game->keys[LEFT]))
        return move_left(game), 0;
    if (!my_strcmp(line, game->keys[RIGHT]))
        return move_right(game), 0;
    if (!my_strcmp(line, game->keys[DROP]))
        return drop_tetrimino(game);
    return 0;
}

static int game_launcher(struct game_props_s *game)
{
    char line[READ_SIZE] = {0};

    initscr();
    my_set_term(0);
    if (setup_game(game) == -1)
        return -1;
    while (1) {
        my_memset(line, '\0', READ_SIZE);
        read(0, line, READ_SIZE);
        if (analyse_keys(game, line) == 1)
            break;
        if (check_too_small_term() == -1)
            continue;
        if (update_game(game) == -1)
            break;
        update_windows(game);
    }
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
