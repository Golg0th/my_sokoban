/*
** EPITECH PROJECT, 2022
** my
** File description:
** my
*/
#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

#pragma once

typedef struct playerpos_s {
    int pos_x;
    int pos_y;
} playerpos_t;

typedef struct opos_s {
    int pos_y;
    int pos_x;
} opos_t;

typedef struct sokoban_s {
    char **map;
    int key;
    int nb_o;
    playerpos_t *player;
} sokoban_t;

int my_strlen(char const *str);
void my_putstr(char const *str);
int main_loop(char *filepath, sokoban_t *data, opos_t *opos);
void is_box(sokoban_t *data);
char *get_txt_file(const char *filepath);
char **my_stwa(char *str, char const lim);
void movement(sokoban_t *data);
int g_play_pos(sokoban_t *data);
int sysnopsis(void);
void replace_all_o(sokoban_t *data, opos_t *opos, int index);
int check_box(char **map, int i, int j);
int check_lose(char **map);
int check_win(char **map, opos_t *opos, int index);
void printmap(sokoban_t *data, opos_t *opos, int index);
void vertical_moves(sokoban_t *data);
void horizontal_moves(sokoban_t *data);
