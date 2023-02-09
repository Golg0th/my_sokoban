/*
** PERSONNAL PROJECT
** my_sokoban
** File description:
** get_map
*/
#include "../includes/my.h"

static char *stwa_string(char *str, int *co, char const lim, char const *st)
{
    int j = 0;
    int siz = 0;

    for (siz = 0; st[siz + *co] != lim && st[siz + *co] != '\0'; siz++);
    str = malloc(sizeof(char) * (siz + 1));
    if (str == NULL)
        return (NULL);
    for (j = 0; j != siz; j++)
        str[j] = st[j + *co];
    str[siz] = '\0';
    *co += (siz + 1);
    return (str);
}

char **my_stwa(char *str, char lim)
{
    int nb_word = 0;
    int co = 0;
    char **tab;

    for (int i = 0; str[i]; i++)
        if (str[i] == lim)
            nb_word++;
    nb_word++;
    tab = malloc(sizeof(char *) * (nb_word + 1));
    tab[nb_word] = NULL;
    for (int i = 0; i != nb_word; i++) {
        tab[i] = stwa_string(tab[i], &co, lim, str);
    }
    free(str);
    return (tab);
}

int check_string(char *str)
{
    int p = 0;
    int x = 0;
    int o = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != 'P' && str[i] != 'X' && str[i] != 'O' &&
        str[i] != '#' && str[i] != ' ' && str[i] != '\n')
            return (84);
        if (str[i] == 'P')
            p++;
        if (str[i] == 'X')
            x++;
        if (str[i] == 'O')
            o++;
    }
    if (o != x || p != 1 || o == 0)
        return (84);
    return (0);
}

static char *open_file(const char *filepath, char *buffer, const int size)
{
    int fd = 0;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        free(buffer);
        return (NULL);
    }
    if (read(fd, buffer, size) == -1) {
        free(buffer);
        return (NULL);
    }
    close(fd);
    buffer[size] = '\0';
    if (check_string(buffer) == 84) return (NULL);
    return (buffer);
}

char *get_txt_file(const char *filepath)
{
    struct stat stats;
    int size = 0;
    char *buffer;

    stat(filepath, &stats);
    size = stats.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    return (open_file(filepath, buffer, size));
}
