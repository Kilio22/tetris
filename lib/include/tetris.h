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
#include <ncurses.h>
#include <sys/types.h>
#include <curses.h>
#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <my_stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>


#define READ_SIZE 4096
#define KEY_NB 6

typedef char * my_key_t;

enum key_str {
    LEFT,
    RIGHT,
    TURN,
    DROP,
    QUIT,
    PAUSE
};

struct game_props_s {
    size_t level;
    size_t size[2];
    bool next;
    bool debug;
    my_key_t keys[KEY_NB];
    int nb_tetriminos;
};

//utils.c
int my_error(char *str);
int init_game(struct game_props_s *game);
void debug_mode(struct game_props_s *game);
int my_set_term(int status);

extern const struct option optlist[];
extern const struct game_props_s default_tetris;
extern const char *key_term[];
extern const char *my_key_print[];
#endif /* !TETRIS_H_ */
