/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** menu
*/

#include "my.h"
#include "tetris.h"

static int print_too_little_term(void)
{
    if (COLS < 190 || LINES < 45) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 8, "ENLARGE/DEZOOM YOUR TERMINAL");
        refresh();
        return 1;
    }
    return 0;
}

static void print_menu(int highlight, char ***logo)
{
    int y = 6;
    static int color = 1;

    if (print_too_little_term() == 1)
        return;
    for (int i = 0; logo[0][i]; i++, y++) {
        attron(COLOR_PAIR(color));
        mvprintw(y, (COLS / 2) - 60, logo[0][i]);
        attroff(COLOR_PAIR(color));
        color += color < 200 ? 1 : -200;
    }
    y += 10;
    for (int i = 0; i < 2; i++) {
        if (i == highlight)
            attron(COLOR_PAIR(209));
        for (int j = 0; logo[i + 1][j]; j++, y++)
                mvprintw(y, COLS / 2 - 23, logo[i + 1][j]);
        attroff(COLOR_PAIR(209));
    }
}

static int check_line(int *highlight, char key)
{
    if (key == 'A' && (*highlight) > 0)
        (*highlight)--;
    if (key == 'B' && (*highlight) < 1)
        (*highlight)++;
    if (key == 10)
        return 1;
    return 0;
}

int menu(void)
{
    int highlight = 0;
    char key;
    char ***logo = get_logo("src/ascii.txt");

    if (!logo)
        return 84;
    while (42) {
        clear();
        print_menu(highlight, logo);
        refresh();
        key = getch();
        if (check_line(&highlight, key) == 1)
            break;
    }
    for (int i = 0; i < 3; i++)
        my_free_fields(logo[i]);
    free(logo);
    return highlight;
}