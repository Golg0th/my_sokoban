/*
** EPITECH PROJECT, 2023
** win or loose
** File description:
** win_or_loose
*/

#include "../includes/my.h"

int check_lose(char **map)
{
    int j = 0;
    for (int i = 0; map[i + 1];) {
        if (map[i][j] == '\0') {
            j = 0;
            i++;
        }
        if (check_box(map, i, j) == 0)
            return (1);
        j++;
    }
    return (0);
}

int check_win(char **map, opos_t *opos, int index)
{
    for (int i = 0; i < index; i++) {
        if (map[opos[i].pos_y][opos[i].pos_x] != 'X')
            return (1);
    }
    return (0);
}
