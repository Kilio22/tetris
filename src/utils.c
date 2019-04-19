/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** utils
*/

#include "tetris.h"

int my_error(char *str)
{
    my_dprintf(2, "%s\n", str);
    exit(84);
}