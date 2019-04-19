/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** my_set_term
*/

#include <termios.h>
#include "tetris.h"

int my_set_term(int status)
{
    static struct termios old;
    struct termios new;

    if (status == 0) {
        if (ioctl(0, TCGETS, &old) || ioctl(0, TCGETS, &new))
            return my_error(strerror(errno));
        new.c_lflag &= ~ECHO;
        new.c_lflag &= ~ICANON;
        new.c_cc[VTIME] = 1;
        new.c_cc[VMIN] = 0;
        if (ioctl(0, TCSETS, &new))
            return my_error(strerror(errno));
    } else {
        if (ioctl(0, TCSETS, &old))
            return my_error(strerror(errno));
    }
    return 0;
}