/*
** PERSONNAL PROJECT
** my_sokoban
** File description:
** utils files
*/

#include "../includes/my.h"

int my_strlen(char const *str)
{
    int i = 0;
    for (; str[i]; i++)
    return (i);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void replace_all_o(sokoban_t *data, opos_t *opos, int index)
{
    for (int i = 0; i < index; i++) {
        if (data->map[opos[i].pos_y][opos[i].pos_x] == ' ')
            data->map[opos[i].pos_y][opos[i].pos_x] = 'O';
    }
}

void printmap(sokoban_t *data, opos_t *opos, int index)
{
    replace_all_o(data, opos, index);
    for (int i = 0; data->map[i]; i++)
        printw("%s\n", data->map[i]);
}

int check_box(char **map, int i, int j)
{
    if (map[i][j] != 'X') return (1);
    if (map[i + 1][j] == '#' && map[i][j + 1] == '#' || map[i + 1][j] == '#' &&
    map[i][j - 1] == '#' || map[i][j - 1] == '#' &&
    map[i - 1][j] == '#' || map[i][j + 1] == '#' && map[i - 1][j] == '#')
        return (1);
    return (0);
}
