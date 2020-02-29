/*
** EPITECH PROJECT, 2018
** dante
** File description:
** generator.h
*/

#include "my.h"
#include <SDL/SDL.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>

#ifndef GEN_H
#define GEN_H

    #define UP (0)
    #define DOWN (1)
    #define LEFT (2)
    #define RIGHT (3)
    #define BLOCKED (-1)
    #define EMPTY_LIST (84)

typedef struct node_s {
    struct node_s *prev;
    struct node_s *next;
    int x;
    int y;
}node_t;

typedef struct control_s {
    node_t *first;
    node_t *last;
}control_t;

typedef struct {
    int x;
    int y;
    int r;
    int c;
    char **map;
    int *pos_blocked;
    int rand_value;
    control_t *pos;
    int done;
    int blocked;
    int imp;
    int end;
    int lib;
}data_t;

void create_perfect(char **, int, int);
char **create_map(int, int);
void backtrack(data_t *);
void *add_node(int , int , control_t *);
void free_list(control_t *);
void free_struct(data_t *);
void final_disp(data_t *);
void imperfect_it(data_t *);
void dig(data_t *);
void check_up(data_t *);
void check_down(data_t *);
void check_left(data_t *);
void check_right(data_t *);
void create_end(data_t *);
void print_usage(void);
void dig_maze(data_t *);
void sdl_display(data_t *);
void graphical_maze(data_t *);
void csfml_display(data_t *);

#endif