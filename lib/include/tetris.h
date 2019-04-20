/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_


#include <linux/limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include <ncurses.h>
#include <term.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include "my_string.h"
#include "my_stdio.h"

#define READ_SIZE 4096
#define KEY_NB 6
#define FREE_FIELDS(a) my_free_fields(a), NULL
#define IS_TETRIMINO_FILE(dtype, dname, fname) ( \
        dtype == DT_REG && \
        !access(fname, R_OK) && \
        my_str_ends_with(dname, ".tetrimino") \
    )

enum win_name {
    SCORE,
    GAME,
    NEXT,
    WIN_NAME_MAX
};
#define NB_WINDOW (WIN_NAME_MAX - game->next)

typedef char * my_key_t;

enum key_str {
    LEFT,
    RIGHT,
    TURN,
    DROP,
    QUIT,
    PAUSE
};

struct tetrimino_s {
    char *name;
    size_t width;
    size_t height;
    unsigned char color;
    char **piece[4];
    bool valid;
};

struct game_props_s {
    size_t level;
    size_t score;
    size_t size[2];
    bool next;
    bool debug;
    my_key_t keys[KEY_NB];
    int nb_tetriminos;
    struct tetrimino_s **tetriminos;
    char **map;
    WINDOW *win[3];
};

//load tetriminos
int load_tetriminos(struct game_props_s *game);
void sort_tetriminos(struct tetrimino_s **tetriminos);
char **parse_first_line(FILE *f_stream);
void analyse_tetrimino_file(char *filepath, char *tetri_name,
                            struct game_props_s *game);
char **analyse_tetrimino_props(char *line);
struct tetrimino_s *init_tetrimino(FILE *f_stream, char *tetri_name);
struct tetrimino_s **realloc_tetrimino(struct tetrimino_s **old,
struct tetrimino_s *to_add);
char **scan_piece(FILE *f_stream, struct tetrimino_s *tetrimino);

int display_help(int argc, char *argv[]);

/* modifies the tetris properties according to the arguments */
int modify_game_props(int argc, char *argv[], struct game_props_s *game);
extern const struct option optlist[];

//utils.c
int my_error(char *str);

//init_game.c
int init_game(struct game_props_s *game);

//debug
void debug_mode(struct game_props_s *game);

//set terminal
int my_set_term(int status);

//print_windows
void print_score_board(WINDOW *win, struct game_props_s *game);
void print_next(WINDOW *win, struct game_props_s *game);

//window_managment
void update_windows(struct game_props_s *game);
int create_windows(struct game_props_s *game);

extern const char *key_term[];
extern const char *my_key_print[];

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

#endif /* !TETRIS_H_ */
