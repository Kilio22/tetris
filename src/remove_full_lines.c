/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** remove_full_lines
*/

#include "tetris.h"

static bool is_full_line(struct map_s *line, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (line[i].id == 0)
            return false;
    }
    return true;
}

static void remove_line(struct map_s **map, size_t size, size_t line)
{
    struct map_s tmp;

    for (size_t i = 0; i < size; i++) {
        map[line][i].c = ' ';
        map[line][i].color = 0;
        map[line][i].id = 0;
    }
    for (size_t i = line; i - 1 < line; i--) {
        for (size_t j = 0; j < size; j++) {
            tmp = map[i][j];
            map[i][j] = map[i - 1][j];
            map[i - 1][j] = tmp;
        }
    }
}

void remove_full_lines(struct game_props_s *game)
{
    static size_t completed = 0;
    size_t completed_tmp = 0;

    for (size_t i = 0; i < game->size[0]; i++) {
        if (is_full_line(game->map[i], game->size[1])) {
            remove_line(game->map, game->size[1], i);
            ++completed_tmp;
        }
    }
    game->score += 100 * completed_tmp;
    completed += completed_tmp;
    if (completed >= 10) {
        ++game->level;
        completed -= 10;
    }
}
