/*
** EPITECH PROJECT, 2022
** box
** File description:
** deplace boxes
*/

#include "../includes/my.h"

void box_above(sokoban_t *data)
{
    if (data->map[data->player->pos_y - 1][data->player->pos_x] == 'X'
    && data->key == KEY_UP) {
        if (data->map[data->player->pos_y - 2][data->player->pos_x] == '#'
        || data->map[data->player->pos_y - 2 ][data->player->pos_x] == 'X' ) {
            data->player->pos_y += 1;
            return;
        } data->map[data->player->pos_y - 2][data->player->pos_x] = 'X';
        data->map[data->player->pos_y][data->player->pos_x] = ' ';
        return;
    } else
        return;
}

void box_under(sokoban_t *data)
{
    if (data->map[data->player->pos_y + 1][data->player->pos_x] == 'X'
    && data->key == KEY_DOWN) {
        if (data->map[data->player->pos_y + 2][data->player->pos_x] == '#'
        || data->map[data->player->pos_y + 2][data->player->pos_x] == 'X') {
            data->player->pos_y -= 1;
            return;
        } data->map[data->player->pos_y + 2][data->player->pos_x] = 'X';
        data->map[data->player->pos_y][data->player->pos_x] = ' ';
        return;
    } else
        return;
}

void box_left(sokoban_t *data)
{
    if (data->map[data->player->pos_y][data->player->pos_x - 1] == 'X'
    && data->key == KEY_LEFT) {
        if (data->map[data->player->pos_y][data->player->pos_x - 2] == '#'
        || data->map[data->player->pos_y][data->player->pos_x - 2] == 'X') {
            data->player->pos_x += 1;
            return;
        }
        data->map[data->player->pos_y][data->player->pos_x - 2] = 'X';
        data->map[data->player->pos_y][data->player->pos_x] = ' ';
        return;
    } else
        return;
}

void box_right(sokoban_t *data)
{
    if (data->map[data->player->pos_y][data->player->pos_x + 1] == 'X'
    && data->key == KEY_RIGHT) {
        if (data->map[data->player->pos_y][data->player->pos_x + 2] == '#'
        || data->map[data->player->pos_y][data->player->pos_x + 2] == 'X') {
            data->player->pos_x -= 1;
            return;
        }
        data->map[data->player->pos_y][data->player->pos_x + 2] = 'X';
        data->map[data->player->pos_y][data->player->pos_x] = ' ';
        return;
    } else
        return;
}

void is_box(sokoban_t *data)
{
    if (data->key == KEY_RIGHT) {
        box_right(data);
        return;
    } if (data->key == KEY_LEFT) {
        box_left(data);
        return;
    } if (data->key == KEY_UP) {
        box_above(data);
        return;
    } if (data->key == KEY_DOWN) {
        box_under(data);
        return;
    }
}
