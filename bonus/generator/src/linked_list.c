/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** TODO: add description
*/

#include "generator.h"

void *add_node(int x, int y, control_t *pos)
{
    node_t *new_node = malloc(sizeof(node_t));

    new_node->x = x;
    new_node->y = y;
    new_node->prev = NULL;
    new_node->next = NULL;
    if (!pos) {
        pos = malloc(sizeof(control_t));
        pos->first = new_node;
        pos->last = new_node;
    } else {
        pos->last->next = new_node;
        new_node->prev = pos->last;
        pos->last = pos->last->next;
    }
    return (pos);
}

int list_size(control_t *list)
{
    int size = 0;

    for (node_t *tmp = list->first; tmp; tmp = tmp->next, size++);
    return (size);
}

void free_list(control_t *list)
{
    node_t *node = list->first;
    node_t *tmp = NULL;

    if (node == NULL)
        exit (EMPTY_LIST);
    while (node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    free(list);
}