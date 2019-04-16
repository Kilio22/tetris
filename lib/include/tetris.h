/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <stdbool.h>
#include <getopt.h>

typedef int key_t;

struct key_settings_s {
    key_t left;
    key_t right;
    key_t turn;
    key_t drop;
    key_t quit;
    key_t pause;
};

struct game_props_s {
    size_t level;
    size_t size[2];
    bool next;
    bool debug;
    struct key_settings_s key_codes;
};

extern const struct option optlist[];
extern const struct game_props_s default_tetris;

#endif /* !TETRIS_H_ */
