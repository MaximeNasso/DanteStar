/*
** EPITECH PROJECT, 2018
** dante
** File description:
** solver.h
*/

typedef struct {
    int y_max;
    int x_max;
    int y;
    int x;
    char **maze;
    int **i_maze;
    int lib;
}data_t;

typedef struct node {
    int x;
    int y;
    struct node *prev;
    struct node *next;
    struct list *path;
}intersection_t;

typedef struct list {
    intersection_t *tail;
    intersection_t *head;
}list_t;

//solver_manager.c
int solver_manager(char **, data_t *);
void backtrack(data_t *, list_t *);
void move_algo(data_t *, int, int, list_t *);
int solver_algo(data_t *data, sfRenderWindow *window, sfEvent event, sfRectangleShape *dig);
void solve_loop(data_t *data, list_t *list, sfRenderWindow *window, sfEvent event, sfRectangleShape *dig);

//solver_manager_bis.c
void check_start_end(data_t *);
int check_coord(data_t *, int, int);
void create_final_maze(data_t *, list_t *);

//data_manager.c
int get_data(data_t *, char **);
int get_y(data_t *);
char *get_maze(char **, data_t *);
int **create_i_maze(data_t *);
int **create_sol_tab(int, int);

//init_struct.c
data_t *init_data(void);
list_t *add_node(list_t *, int, int);

//tools_functions.c
int print_tab_bis(char **, data_t *);
void print_int_tab(int, int, int **);
int check_file(char *);

//free_manager.c
int free_manager(data_t *);
int free_int_tab(int **, data_t *);

void csfml_display(data_t *data);
void draw_map(data_t *data, sfRenderWindow *win, sfRectangleShape *dig);
sfRenderWindow *my_window(unsigned int widht, unsigned int height);