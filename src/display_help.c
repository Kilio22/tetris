/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** display_help
*/

#include "tetris.h"
#include "my_string.h"
#include "my_stdio.h"

static int print_help(char *bin_name)
{
    my_printf("Usage: %s [options]\n", bin_name);
    my_puts("Options:");
    my_puts(" --help \t\tDisplay this help");
    my_puts(" -L --level={num} \tStart Tetris at level num (def: 1)");
    my_putstr(" -l --key-left={K} \tMove the tetrimino LEFT using the K key ");
    my_puts("(def: left arrow)");
    my_putstr(" -r --key-right={K} \tMove the tetrimino RIGHT using the K key");
    my_puts(" (def: right arrow)");
    my_putstr(" -t --key-turn={K} \tTURN the tetrimino clockwise 90d using ");
    my_puts("the K key (def: top arrow)");
    my_putstr(" -d --key-drop={K} \tDROP the tetrimino using the K key ");
    my_puts("(def: down arrow)");
    my_putstr(" -q --key-quit={K} \tQUIT the game using the K key (def: ");
    my_puts("‘q’ key)");
    my_putstr(" -p --key-pause={K} \tPAUSE/RESTART the game using the K key ");
    my_puts("(def: space bar)");
    my_putstr(" --map-size={row,col} \tSet the numbers of rows and columns ");
    my_puts("of the map (def: 20,10)");
    my_puts(" -w --without-next \tHide next tetrimino (def: false)");
    my_puts(" -D --debug \t\tDebug mode (def: false)");
    return 1;
}

int display_help(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        if (STR_EQ("--help", argv[i]))
            return print_help(argv[0]);
    }
    return 0;
}
