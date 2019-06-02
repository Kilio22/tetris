/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** init_menu
*/

#include "my.h"
#include "tetris.h"

static char ***init_tab(void)
{
    char ***new = malloc(sizeof(char **) * 3);

    if (!new)
        return NULL;
    for (int i = 0; i < 3; i++) {
        new[i] = malloc(sizeof(char *));
        if (!new[i])
            return NULL;
        new[i][0] = NULL;
    }
    return new;
}

static int get_file_logo(char ****logo, FILE *stream)
{
    char *line = NULL;
    int i = 0;
    int j = 0;

    while ((line = get_line(stream)) != NULL) {
        if (j == 9) {
            i++;
            j = 0;
        }
        (*logo)[i] = my_realloc_array((*logo)[i], line);
        if (!(*logo))
            return -1;
        free(line);
        j++;
    }
    return 0;
}

char ***get_logo(void)
{
    FILE *stream = fopen("src/ascii.txt", "r");
    char ***logo = init_tab();

    if (!stream || !logo) {
        free(logo);
        exit(84);
    }
    if (get_file_logo(&logo, stream) == -1)
        exit(84);
    return logo;
}