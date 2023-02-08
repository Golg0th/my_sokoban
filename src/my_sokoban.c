/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Desc
*/

#include "../includes/my.h"

int check_h(char const *acomp, char const *base)
{
    if (my_strlen(acomp) != my_strlen(base))
        return (1);
    for (int i = 0; acomp[i]; i++) {
        if (acomp[i] != base[i])
            return (1);
    }
    return (0);
}

int sysnopsis(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the warehouse map, ");
    my_putstr("containing '#' for walls,\n");
    my_putstr("     'P' for the player, 'X' for boxes and 'O'");
    my_putstr(" for storage locations.\n");
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        write(2, "ERROR : invalid number of arguments\n", 36);
        return (84);
    }
    if (check_h(av[1], "-h") == 0) {
        sysnopsis();
        return (0);
    }
    sokoban_t sokoban;
    opos_t *opos = malloc(sizeof(opos_t) * 1000);
    return (main_loop(av[1], &sokoban, opos));
}
