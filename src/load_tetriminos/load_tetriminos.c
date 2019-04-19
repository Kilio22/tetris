/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** load_tetriminos
*/

#include <linux/limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tetris.h"
#include "my.h"
#include "my_stdio.h"
#include "my_string.h"

int is_readable_directory(const char *path);
char *my_strcat_nofree(const char *left, const char *right);

#define FREE_FIELDS(a) my_free_fields(a), NULL
#define IS_TETRIMINO_FILE(dtype, dname, fname) ( \
        dtype == DT_REG && \
        !access(fname, R_OK) && \
        my_str_ends_with(dname, ".tetrimino") \
    )

static struct tetrimino_s *create_tetrimino(char *name)
{
    struct tetrimino_s *t = malloc(sizeof(struct tetrimino_s));

    if (!t)
        return NULL;
    t->name = my_strndup(name, my_strlen(name) - 10);
    t->width = 0;
    t->height = 0;
    t->color = 0;
    t->piece = NULL;
    t->valid = false;
    return t;
}

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

struct tetrimino_s *init_tetrimino(FILE *f_stream, char *tetri_name)
{
    struct tetrimino_s *t = create_tetrimino(tetri_name);
    char **array = parse_first_line(f_stream);

    if (!array)
        return t;
    t->width = my_atoi(array[0]);
    t->height = my_atoi(array[1]);
    t->color = my_atoi(array[2]);
    my_free_fields(array);
    t->piece = scan_piece(f_stream, t);
    if (t->name && t->width && t->height && t->color && t->piece)
        t->valid = true;
    return t;
}

struct tetrimino_s **realloc_tetrimino(struct tetrimino_s **old, struct tetrimino_s *to_add)
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

int scan_directory(char *folderpath, struct game_props_s *game)
{
    DIR *dir = opendir(folderpath);
    struct dirent *dirent;
    char *file_name;

    if (!dir)
        return -1;
    dirent = readdir(dir);
    while (dirent) {
        file_name = my_strcat_nofree(folderpath, dirent->d_name);
        if (IS_TETRIMINO_FILE(dirent->d_type, dirent->d_name, file_name))
            analyse_tetrimino_file(file_name, dirent->d_name, game);
        free(file_name);
        dirent = readdir(dir);
    }
    closedir(dir);
    return 0;
}

int load_tetriminos(struct game_props_s *game)
{
    char *tetriminos_folder_name = "tetriminos/";

    if (!is_readable_directory(tetriminos_folder_name))
        return 84;
    scan_directory(tetriminos_folder_name, game);
    return 0;
}
