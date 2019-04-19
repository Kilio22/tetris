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

/* displays help then leaves if it did */
int display_help(int argc, char *argv[]);

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

extern const struct game_changer_s args[];

#endif /* !TETRIS_H_ */
