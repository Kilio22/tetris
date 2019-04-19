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

const struct option optlist[] = {
    {"help", no_argument, 0, 0},
    {"level", required_argument, 0, 'L'},
    {"key-left", required_argument, 0, 'l'},
    {"key-right", required_argument, 0, 'r'},
    {"key-turn", required_argument, 0, 't'},
    {"key-drop", required_argument, 0, 'd'},
    {"key-quit", required_argument, 0, 'q'},
    {"key-pause", required_argument, 0, 'p'},
    {"map-size", required_argument, 0, 0},
    {"without-next", no_argument, 0, 'w'},
    {"debug", no_argument, 0, 'D'},
    {0, 0, 0, 0}
};

const char *key_term[] = {
    "kcub1",
    "kcuf1",
    "kcuu1",
    "kcud1",
    "q",
    " "
};

const char *my_key_print[] = {
    "Key Left",
    "Key Right",
    "Key Turn",
    "Key Drop",
    "Key Quit",
    "Key Pause"
};