/*
** EPITECH PROJECT, 2022
** mouvement
** File description:
** mouvement
*/

#include "../includes/my.h"

void horizontal_moves(sokoban_t *data)
{
    if (data->key == KEY_RIGHT) {
        is_box(data);
        data->player->pos_x += 1;
        data->map[data->player->pos_y][data->player->pos_x] = 'P';
        return;
    }
    if (data->key == KEY_LEFT) {
        is_box(data);
        data->player->pos_x -= 1;
        data->map[data->player->pos_y][data->player->pos_x] = 'P';
        return;
    }
}

void vertical_moves(sokoban_t *data)
{
    if (data->key == KEY_UP) {
        is_box(data);
        data->player->pos_y -= 1;
        data->map[data->player->pos_y][data->player->pos_x] = 'P';
        return;
    }
    if (data->key == KEY_DOWN) {
        is_box(data);
        data->player->pos_y += 1;
        data->map[data->player->pos_y][data->player->pos_x] = 'P';
        return;
    }

}
