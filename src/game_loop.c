/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** game_loop
*/

#include <time.h>
#include "tetris.h"

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

static bool time_to_drop(size_t level)
{
    clock_t curr = clock();
    static clock_t prev = 0;
    double diff;

    if (!prev)
        prev = curr;
    diff = (double)(curr - prev) / CLOCKS_PER_SEC;
    if (diff > (.05 - level * .005)) {
        prev = curr;
        return true;
    }
    return false;
}

void game_loop(struct game_props_s *game)
{
    char line[READ_SIZE] = {0};
    bool drop = false;

    while (1) {
        my_memset(line, '\0', READ_SIZE);
        read(0, line, READ_SIZE);
        drop = time_to_drop(game->level);
        if (analyse_key_pressed(game, line) != 0)
            break;
        if (check_too_small_term() == -1)
            continue;
        if (update_game(game, drop) == -1)
            break;
        update_windows(game);
    }
}
