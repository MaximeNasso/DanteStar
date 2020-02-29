/*
** EPITECH PROJECT, 2019
** dante
** File description:
** data_manager.c
*/

#include "my.h"

int get_data(data_t *data, char **av)
{
    char *str = NULL;

    str = get_maze(av, data);
    check_file(str);
    free(str);
    return (0);
}

int get_y(data_t *data)
{
    int y = 0;

    for (int i = 0; data->maze[i]; ++i)
        ++y;
    return (y);
}

char *get_maze(char **av, data_t *data)
{
    struct stat file;
    char *buf = NULL;
    int fd = open(av[1], O_RDONLY);

    stat(av[1], &file);
    if (file.st_size == 0) {
        printf("no solution found");
        exit (0);
    }
    buf = malloc(sizeof(char) * (file.st_size + 1));
    read(fd, buf, file.st_size);
    if (file.st_size == 1 && buf[0] == '\n') {
        printf("no solution found");
        exit (0);
    }
    close(fd);
    buf[file.st_size] = '\0';
    data->maze = my_str_to_word_array(buf, data);
    return (buf);
}

int **create_i_maze(data_t *data)
{
    int **map = malloc(sizeof(int *) * (data->y_max));

    for (int y = 0; y < data->y_max; ++y) {
        map[y] = malloc(sizeof(int) * data->x_max);
        for (int x = 0; x < data->x_max; ++x) {
            if (data->maze[y][x] == '*')
                map[y][x] = 0;
            if (data->maze[y][x] == 'X')
                map[y][x] = 1;
        }
    }
    return (map);
}