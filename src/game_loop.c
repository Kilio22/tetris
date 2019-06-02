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

static void get_piece_center(struct game_props_s *game,
                                struct tetrimino_s *piece, size_t *center)
{
    size_t i = 0;
    size_t j = 0;

    (void)center;
    for (; game->map[i] && my_find_char_inmap(game->map, i, game, '*') == -1; i++);
    i += piece->height / 2;
    for (; j < game->size[1]; j++) {
        if (game->map[i][j].id == 2)
            break;
    }
    if (piece->width % 2 == 0)
        j += piece->width / 2 - 1;
    else
        j += piece->width / 2;
//    fprintf(stderr, "%ld %ld\n", i, j);
}

void game_loop(struct game_props_s *game)
{
    char line[READ_SIZE] = {0};
    bool drop = false;
    size_t center[2] = {0, 0};

    while (1) {
        my_memset(line, '\0', READ_SIZE);
        read(0, line, READ_SIZE);
        get_piece_center(game, game->curr, center);
        if (analyse_key_pressed(game, line) != 0)
            break;
        if (check_too_small_term() == -1)
            continue;
        drop = time_to_drop(game->level);
        if (update_game(game, drop) == -1)
            break;
        update_windows(game);
    }
}
