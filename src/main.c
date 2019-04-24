/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include <time.h>
#include "tetris.h"
#include "my_string.h"

static int setup_game(struct game_props_s *game)
{
    curs_set(0);
    if (create_windows(game) == -1)
        return -1;
    if (!game->next)
        print_next(game->win[NEXT], game);
    print_score_board(game->win[SCORE], game);
    for (int i = 0; i < NB_WINDOW; i++)
        wrefresh(game->win[i]);
    return 0;
}

static int destroy_game(struct game_props_s *game)
{
    for (int i = 0; i < NB_WINDOW; i++)
        delwin(game->win[i]);
    endwin();
    return 0;
}

static int game_launcher(struct game_props_s *game)
{
    char line[READ_SIZE] = {0};
    ssize_t n_read;

    if (setup_game(game) == -1)
        return -1;
    while (1) {
        n_read = read(0, line, READ_SIZE);
        if (my_strcmp(game->keys[QUIT], line) == 0)
            break;
        my_memset(line, '\0', n_read);
        update_windows(game);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    struct game_props_s game;
    int n_return;

    if (display_help(argc, argv))
        return 0;
    srand(time(NULL));
    init_game(&game);
    if (modify_game_props(argc, argv, &game) == 84)
        return 84;
    if (load_tetriminos(&game) == 84)
        return 84;
    if (game.debug == true)
        debug_mode(&game);
    initscr();
    my_set_term(0);
    if (game_launcher(&game) == -1)
        n_return = 84;
    my_set_term(1);
    destroy_game(&game);
    return n_return;
}
