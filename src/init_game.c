/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** init_game
*/

#include "tetris.h"
#include "my_string.h"
#include "my.h"

int check_term_size(struct game_props_s *game)
{
    int nb_lig_n = tigetnum("lines");
    int nb_cols_n = tigetnum("cols");

    if (nb_lig_n < (int)game->size[0])
        return -1;
    if (nb_cols_n < (int)game->size[1])
        return -1;
    return 0;
}

int init_keys(struct game_props_s *game)
{
    int err;

    if (setupterm(game->term, 1, &err))
        return my_error(strerror(errno));
    for (int i = 0; i < 4; i++)
        game->keys[i] = my_strdup(tigetstr(key_term[i]));
    game->keys[QUIT] = my_strdup(key_term[QUIT]);
    game->keys[PAUSE] = my_strdup(key_term[PAUSE]);
    return 0;
}

int init_base(struct game_props_s *game)
{
    game->level = 1;
    game->size[0] = 20;
    game->size[1] = 10;
    game->next = false;
    game->debug = false;
    game->nb_tetriminos = 0;
    game->tetriminos = malloc(sizeof(struct tetrimino_s *));
    game->tetriminos[0] = NULL;
    game->score = 0;
    game->rotation = 0;
    return 0;
}

int init_game(struct game_props_s *game, char **env)
{
    int i = 0;
    char *buff = NULL;

    for (; env[i] && my_strncmp(env[i], "TERM", 4); i++);
    if (!env[i])
        return my_error("Cannot find TERM var\n");
    game->term = my_strdup(&env[i][5]);
    init_base(game);
    init_keys(game);
    buff = tigetstr("smkx");
    if (check_term_size(game))
        return my_error("Too small terminal");
    if (buff == NULL)
        return 0;
    if (putp(buff) == -1)
        return my_error(strerror(errno));
    return 0;
}
