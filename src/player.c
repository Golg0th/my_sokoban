/*
** EPITECH PROJECT, 2022
** movement
** File description:
** movement
*/

#include "../includes/my.h"

int g_play_pos_loop(sokoban_t *data, int i, int j)
{
    for (j = 0; data->map[i][j]; j++) {
        if (data->map[i][j] == 'P') {
            data->player->pos_x = j;
            data->player->pos_y = i;
            data->map[i][j] = ' ';
            return (0);
        }
    }
}

int g_play_pos(sokoban_t *data)
{
    int i = 0;
    int j = 0;

    for (; data->map[i]; i++) {
        g_play_pos_loop(data, i, j);
    }
}

void check_collision(sokoban_t *data)
{
    if (data->key == KEY_UP &&
    data->map[data->player->pos_y - 1][data->player->pos_x] == '#') {
        data->player->pos_y += 1;
        return;
    }
    if (data->key == KEY_DOWN &&
    data->map[data->player->pos_y + 1][data->player->pos_x] == '#') {
        data->player->pos_y -= 1;
        return;
    }    if (data->key == KEY_LEFT &&
    data->map[data->player->pos_y][data->player->pos_x - 1] == '#') {
        data->player->pos_x += 1;
        return;
    }    if (data->key == KEY_RIGHT &&
    data->map[data->player->pos_y][data->player->pos_x + 1] == '#') {
        data->player->pos_x -= 1;
        return;
    }
}

void bad_input(sokoban_t *data)
{
    data->map[data->player->pos_y][data->player->pos_x] = 'P';
}

void movement(sokoban_t *data)
{
    check_collision(data);
    if (data->key == KEY_RIGHT || data->key == KEY_LEFT) {
        horizontal_moves(data);
        return;
    }
    if (data->key == KEY_UP || data->key == KEY_DOWN) {
        vertical_moves(data);
        return;
    }
    bad_input(data);
}
