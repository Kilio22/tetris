/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** analyse_tetrimino
*/

#include "tetris.h"
#include "my.h"
#include "my_string.h"

char **analyse_tetrimino_props(char *line)
{
    char **array = my_str_towordarray(line, " \t");

    free(line);
    if (!array)
        return NULL;
    if (my_strarraylen(array) != 3)
        return FREE_FIELDS(array);
    if (!my_str_isnum(array[0], 0))
        return FREE_FIELDS(array);
    if (!my_str_isnum(array[1], 0))
        return FREE_FIELDS(array);
    if (!my_str_isnum(array[2], 0))
        return FREE_FIELDS(array);
    return array;
}

char **parse_first_line(FILE *f_stream)
{
    char *line = NULL;
    size_t n = 0;
    ssize_t n_read;
    char **array;

    n_read = getline(&line, &n, f_stream);
    if (n_read == -1 || !line)
        return NULL;
    if (line[n_read - 1] == '\n')
        line[n_read - 1] = '\0';
    array = analyse_tetrimino_props(line);
    if (!array)
        return NULL;
    return array;
}

void analyse_tetrimino_file(char *filepath, char *tetri_name,
                            struct game_props_s *game)
{
    FILE *f_stream = fopen(filepath, "r");
    struct tetrimino_s *t;

    if (!f_stream)
        return;
    t = init_tetrimino(f_stream, tetri_name);
    game->tetriminos = realloc_tetrimino(game->tetriminos, t);
    game->nb_tetriminos++;
}