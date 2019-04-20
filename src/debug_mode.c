/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** debug_mode
*/

#include "my_string.h"
#include "tetris.h"

void print_keys(struct game_props_s *game, int i)
{
    for (int j = 0; game->keys[i][j]; j++) {
        if (game->keys[i][j] == 27) {
            write(1, "^E", 2);
            my_printf("%s", &game->keys[i][j + 1]);
            return;
        }
        my_printf("%s", &game->keys[i][j]);
    }
}

void print_debug(struct game_props_s *game)
{
    my_puts("*** DEBUG MODE ***");
    for (int i = 0; i < 6; i++) {
        my_printf("%s : ", my_key_print[i]);
        if (my_strcmp(" ", game->keys[i]) == 0) {
            my_printf("(space)\n");
            continue;
        }
        print_keys(game, i);
        my_printf("\n");
    }
    my_printf("Next : %s\n", (game->next == false ? "Yes" : "No"));
    my_printf("Level : %d\n", game->level);
    my_printf("Size : %d*%d\n", game->size[0], game->size[1]);
    my_printf("Tetriminos : %d\n", game->nb_tetriminos);
}

void print_tetriminos(struct tetrimino_s **tetri)
{
    for (size_t i = 0; tetri[i]; i++) {
        my_printf("Tetriminos : Name %s : ", tetri[i]->name);
        if (tetri[i]->valid == false) {
            my_printf("Error\n");
            continue;
        }
        my_printf("Size %d*%d : Color %d :\n", tetri[i]->height,
tetri[i]->width, tetri[i]->color);
        for (size_t j = 0; tetri[i]->piece[j]; j++)
            my_printf("%s\n", tetri[i]->piece[j]);
    }
}

void debug_mode(struct game_props_s *game)
{
    char buff[READ_SIZE] = {0};

    print_debug(game);
    print_tetriminos(game->tetriminos);
    my_printf("Press any key to start Tetris\n");
    my_set_term(0);
    while (my_strlen(buff) <= 0)
        read(0, buff, READ_SIZE);
    my_set_term(1);
}
