/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include "tetris.h"
#include "my_string.h"

void game_luncher(struct game_props_s *game)
{
    char line[READ_SIZE] = {0};

    initscr();
    curs_set(0);
    create_windows(game);
    print_next(game->win[1], game);
    print_score_board(game->win[0], game);
    for (int i = 0; i < 3; i++)
        wrefresh(game->win[i]);
    while (1) {
        read(0, line, READ_SIZE);
        if (my_strcmp(game->keys[QUIT], line) == 0) {
            endwin();
            return;
        }
        for (size_t i = 0; i < READ_SIZE; i++)
            line[i] = '\0';
        update_windows(game);
    }
}

int main(int argc, char *argv[])
{
    struct game_props_s game;

    if (display_help(argc, argv))
        return 0;
    init_game(&game);
    if (modify_game_props(argc, argv, &game) == 84)
        return 84;
    if (load_tetriminos(&game) == 84)
        return 84;
    if (game.debug == true)
        debug_mode(&game);
    my_set_term(0);
    game_luncher(&game);
    my_set_term(1);
    return (0);
}
