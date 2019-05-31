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

int my_find_char_inmap_rev(struct map_s **map, int i,
struct game_props_s *game, char c)
{
    for (size_t j = game->size[1] - 1; j > 0; j--)
        if (map[i][j].c == c && map[i][j].id == 2)
            return j;
    return -1;
}

int my_find_char_inmap(struct map_s **map, int i,
struct game_props_s *game, char c)
{
    for (size_t j = 0; j < game->size[1]; j++)
        if (map[i][j].c == c && map[i][j].id == 2)
            return j;
    return -1;
}