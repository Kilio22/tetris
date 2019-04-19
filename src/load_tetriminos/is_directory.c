/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** is_directory
*/

#include <sys/stat.h>
#include <unistd.h>

int is_readable_directory(const char *path)
{
    struct stat path_stat;
    int n_stat = stat(path, &path_stat);

    if (n_stat == -1)
        return 0;
    if (access(path, R_OK) == -1)
        return 0;
    return S_ISDIR(path_stat.st_mode);
}
