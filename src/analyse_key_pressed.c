/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** analyse_key_pressed
*/

#include "tetris.h"
#include "my_string.h"

int analyse_key_pressed(struct game_props_s *game, char *line)
{
    if (STR_EQ(game->keys[QUIT], line))
        return 1;
    if (STR_EQ(game->keys[TURN], line))
        return rotate_current_piece(game);
    if (STR_EQ(game->keys[LEFT], line)) {
        move_left(game);
        return 0;
    }
    if (STR_EQ(game->keys[RIGHT], line)) {
        move_right(game);
        return 0;
    }
    if (STR_EQ(game->keys[DROP], line))
        return drop_tetrimino(game);
    if (STR_EQ(game->keys[PAUSE], line))
        return menu_pause();
    return 0;
}
