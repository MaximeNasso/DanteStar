/*
** EPITECH PROJECT, 2018
** my
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>
#include "solver.h"

int free_tab(char **);
int print_tab(char **);
int my_put_nbr(int);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
int my_put_nbr_base(unsigned int, char *);
int convert_nb_base(int, char *);
int convert_nb_decimal(int);
char *get_next_line(int);
char *my_revstr(char *);
char * my_strcat(char *, char *);
char *my_strcat_free(char *, char *);
char **my_str_to_word_array(const char *, data_t *);
void my_putchar(char);

#endif /* !MY_H_ */