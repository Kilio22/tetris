/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** setup_game
*/

#include <time.h>
#include "my.h"
#include "tetris.h"
#include "my_string.h"

static void get_highscore(struct game_props_s *game)
{
    int fd = open(".highscore", O_RDONLY);
    char *line = NULL;

    if (fd == -1) {
        game->highscore = 0;
        return;
    }
    line = get_next_line(fd);
    close(fd);
    if (!line) {
        game->highscore = 0;
        return;
    }
    if (!my_str_isnum(line, 0)) {
        game->highscore = 0;
        return;
    }
    game->highscore = my_atoi(line);
}

static void get_art(struct game_props_s *game)
{
    int fd = open("src/ascii.txt", O_RDONLY);
    char **ascii = malloc(sizeof(char *));
    char *line = NULL;

    if (fd == -1 || !ascii)
        exit(84);
    ascii[0] = NULL;
    while ((line = get_next_line(fd)) != NULL) {
        ascii = my_realloc_array(ascii, line);
        if (!ascii)
            exit(84);
    }
    close(fd);
    game->ascii_art = ascii;
}

static void init_map(struct game_props_s *game)
{
    size_t i = 0;

    game->map = malloc(sizeof(char *) * (game->size[1] + 1));
    if (!game->map)
        exit(84);
    for (; i < game->size[1]; i++) {
        game->map[i] = malloc(sizeof(char) * (game->size[0] + 1));
        my_memset(game->map[i], '\0', game->size[0] + 1);
    }
    game->map[i] = NULL;
}

int setup_game(struct game_props_s *game)
{
    curs_set(0);
    start_color();
    init_map(game);
    get_art(game);
    get_highscore(game);
    for (int i = 0; i < 255; i++)
        init_pair(i, i, 0);
    if (create_windows(game) == -1)
        return -1;
    get_next_tetriminos(true, game);
    print_ascii_art(game);
    if (!game->next)
        print_next(game->win[NEXT], game);
    print_score_board(game->win[SCORE], game);
    for (int i = 0; i < NB_WINDOW; i++)
        wrefresh(game->win[i]);
    refresh();
    return 0;
}