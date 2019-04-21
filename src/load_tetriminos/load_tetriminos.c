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

static void analyse_tetrimino_file(char *filepath, char *tetri_name,
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

static int scan_directory(char *folderpath, struct game_props_s *game)
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
