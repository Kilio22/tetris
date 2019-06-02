/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** analyse_tetrimino
*/

#include "tetris.h"
#include "my.h"
#include "my_string.h"

static char **analyse_tetrimino_props(char *line)
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

static char **parse_first_line(FILE *stream)
{
    char *line = NULL;
    char **array;

    line = get_line(stream);
    if (!line)
        return NULL;
    array = analyse_tetrimino_props(line);
    if (!array)
        return NULL;
    return array;
}

struct tetrimino_s **realloc_tetrimino(struct tetrimino_s **old,
                                        struct tetrimino_s *to_add)
{
    size_t len = my_arraylen((void **)old) + 2;
    struct tetrimino_s **new = malloc(sizeof(struct tetrimino_s *) * len);
    size_t i = 0;

    for (; old[i]; i++)
        new[i] = old[i];
    new[i++] = to_add;
    new[i] = NULL;
    free(old);
    return new;
}

static struct tetrimino_s *create_tetrimino(char *name)
{
    struct tetrimino_s *t = malloc(sizeof(struct tetrimino_s));

    if (!t)
        return NULL;
    t->name = my_strndup(name, my_strlen(name) - 10);
    t->width = 0;
    t->height = 0;
    t->color = 0;
    t->piece[0] = NULL;
    t->piece[1] = NULL;
    t->piece[2] = NULL;
    t->piece[3] = NULL;
    t->valid = false;
    return t;
}

struct tetrimino_s *init_tetrimino(FILE *stream, char *tetri_name)
{
    struct tetrimino_s *t = create_tetrimino(tetri_name);
    char **array = parse_first_line(stream);

    if (!array)
        return t;
    t->width = my_atoi(array[0]);
    t->height = my_atoi(array[1]);
    t->color = my_atoi(array[2]);
    my_free_fields(array);
    t->piece[0] = scan_piece(stream, t);
    if (t->name && t->width && t->height && t->color && t->piece[0])
        t->valid = true;
    return t;
}
