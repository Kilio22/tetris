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
    for (int i = 0; line[i]; i++)
        if (line[i] != '*' && line[i] != ' ')
            return -1;
    return 0;
}

static int is_valid_piece(char **piece, struct tetrimino_s *tetrimino)
{
    size_t width = tetrimino->width;
    size_t height = tetrimino->height;
    size_t i = 0;

    for (i = 0; piece[i]; i++);
    if (i != height)
        return -1;
    for (i = 0; piece[i]; i++) {
        if (my_strlen(piece[i]) != width)
            return -1;
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
        piece = my_realloc_array(piece, line);
    }
    if (is_valid_piece(piece, tetrimino))
        return NULL;
    return piece;
}
