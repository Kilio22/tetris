/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** global_constants
*/

#include <curses.h>
#include "tetris.h"

const struct game_props_s default_tetris = {
    1,
    {20, 10},
    false,
    false,
    {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, 'q', ' '}
};
