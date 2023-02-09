/*
** PERSONNAL PROJECT
** my_sokoban
** File description:
** main, help flag
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
    write(1, "USAGE\n", 6);
    write(1, "     ./my_sokoban map\n", 22);
    write(1, "DESCRIPTION\n", 12);
    write(1, "     map file representing the warehouse map, ", 45);
    write(1, "containing '#' for walls,\n", 26);
    write(1, "     'P' for the player, 'X' for boxes and 'O'", 45);
    write(1, " for storage locations.\n", 24);
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
    main_loop(av[1], &sokoban, opos);
    free (opos);
    return (0);
}
