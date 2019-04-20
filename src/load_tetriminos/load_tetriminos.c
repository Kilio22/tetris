/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** load_tetriminos
*/

#include "tetris.h"
#include "my.h"
#include "my_stdio.h"
#include "my_string.h"

int is_readable_directory(const char *path);
char *my_strcat_nofree(const char *left, const char *right);

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
    t->piece[0] = scan_piece(f_stream, t);
    if (t->name && t->width && t->height && t->color && t->piece[0])
        t->valid = true;
    return t;
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
    sort_tetriminos(game->tetriminos);
    return 0;
}
