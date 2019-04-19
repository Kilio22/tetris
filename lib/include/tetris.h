/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <sys/types.h>
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
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include "my_string.h"
#include "my_stdio.h"


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

int display_help(int argc, char *argv[]);
/* modifies the tetris properties according to the arguments */
int modify_game_props(int argc, char *argv[], struct game_props_s *game);
extern const struct option optlist[];
extern const struct game_props_s default_tetris;

/* modifier_functions */
struct game_changer_s {
    int (* const change)(struct game_props_s *, char *);
    int opt;
};

int change_next(struct game_props_s *game, char *arg);
int change_level(struct game_props_s *game, char *arg);
int change_debug(struct game_props_s *game, char *arg);
int change_mapsize(struct game_props_s *game, char *arg);
int change_leftkey(struct game_props_s *game, char *arg);
int change_turnkey(struct game_props_s *game, char *arg);
int change_rightkey(struct game_props_s *game, char *arg);
int change_quitkey(struct game_props_s *game, char *arg);
int change_dropkey(struct game_props_s *game, char *arg);
int change_pausekey(struct game_props_s *game, char *arg);

extern const struct game_changer_s args[];

//utils.c
int my_error(char *str);

//init_game.c
int init_game(struct game_props_s *game);

//debug
void debug_mode(struct game_props_s *game);

//set terminal
int my_set_term(int status);

extern const struct option optlist[];
extern const struct game_props_s default_tetris;
extern const char *key_term[];
extern const char *my_key_print[];
#endif /* !TETRIS_H_ */
