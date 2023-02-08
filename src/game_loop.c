/*
** EPITECH PROJECT, 2022
** game_loop
** File description:
** desc
*/

#include "../includes/my.h"

int fill_loop(sokoban_t *data, opos_t *opos, char **map)
{
    int index = 0;
    int j = 0;
    int i = 0;

    for (; map[i + 1];) {
        if (map[i][j] == '\0') {
            j = 0;
            i++;
        }
        if (map[i][j] == 'O') {
            opos[index].pos_x = j;
            opos[index].pos_y = i;
            index++;
        }
        j++;
    }
    data->nb_o = index;
    return (index);
}

int game_loop(sokoban_t *data, opos_t *opos, int index)
{
    int i = 0;
    while (i == 0) {
        data->key = getch();
        clear();
        g_play_pos(data);
        movement(data);
        if (data->key == 32) break;
        printmap(data, opos, index);
        if (check_lose(data->map) == 0)
            i = 1;
        if (check_win(data->map, opos, index) == 0)
            i = 2;
        refresh();
    }
    endwin();
    return (i);
}

int main_loop(char *filepath, sokoban_t *data, opos_t *opos)
{
    int i = 0;
    int index = 0;
    if (get_txt_file(filepath) == NULL) return (84);
    data->player = malloc(sizeof(playerpos_t));
    data->map = my_stwa(get_txt_file(filepath), '\n');
    index = fill_loop(data, opos, data->map);
    initscr();
    keypad(stdscr, TRUE);
    printmap(data, opos, index);
    i = game_loop(data, opos, index);
    if (i == 2)
        i = 0;
    return (i);
}
