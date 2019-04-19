/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** get_tetrimino_pieces
*/

#include "my.h"
#include "tetris.h"

static int is_valid_line(char *line)
{
    for (size_t i = 0; line[i]; i++)
        if (line[i] != '*' && line[i] != ' ')
            return -1;
    return 0;
}

static int is_valid_piece(char **piece, struct tetrimino_s *tetrimino)
{
    size_t cur_width = 0;
    size_t cur_height = 0;

    for (; piece[cur_height]; cur_height++)
        if (my_strlen(piece[cur_height]) > cur_width)
            cur_width = my_strlen(piece[cur_height]);
    if (tetrimino->height != cur_height)
        return -1;
    if (tetrimino->width != cur_width)
        return -1;
    for (size_t i = 0; piece[i]; i++) {
        if (is_valid_line(piece[i]))
            return -1;
    }
    return 0;
}

char **scan_piece(FILE *f_stream, struct tetrimino_s *tetrimino)
{
    ssize_t n_read = 0;
    size_t n = 0;
    char *line = NULL;
    char **piece = malloc(sizeof(char *) * 1);

    piece[0] = NULL;
    while ((n_read = getline(&line, &n, f_stream)) != -1) {
        line[n_read - 1] = '\0';
        for (size_t j = my_strlen(line) - 1; line[j] == ' '; j--)
            line[j] = '\0';
        piece = my_realloc_array(piece, my_strdup(line));
    }
    if (is_valid_piece(piece, tetrimino))
        return NULL;
    return piece;
}
