/*
** EPITECH PROJECT, 2019
** generator
** File description:
** TODO: add description
*/

#include "generator.h"

void draw_end_sdl(data_t *data, SDL_Surface *bck, SDL_Surface *dig, SDL_Rect
pos)
{
    usleep(25000);
    if (data->end == 1) {
        pos.y = (data->y - 2) * 10;
        pos.x = (data->x - 1) * 10;
    }
    if (data->end == 2) {
        pos.x = (data->x - 1) * 10;
        pos.y = (data->y - 2) * 10;
    }
    if (data->end == 3) {
        pos.x = (data->x - 2) * 10;
        pos.y = (data->y - 1) * 10;
    }
    SDL_UpperBlit(dig, NULL, bck, &pos);
    SDL_Flip(bck);
    usleep(25000);
    pos.x = (data->x - 1) * 10;
    pos.y = (data->y - 1) * 10;
    SDL_UpperBlit(dig, NULL, bck, &pos);
    SDL_Flip(bck);
}

void game_loop_sdl(data_t *data, SDL_Surface *bck, SDL_Surface *dig, SDL_Rect
pos)
{
    SDL_Event event;
    int game = 1, done = 0;

    while (game) {
        if (!data->pos->first->next && data->done == 1)
            break;
        if (data->end != 0 && done == 0) {
            draw_end_sdl(data, bck, dig, pos);
            done = 1;
        }
        SDL_UpperBlit(dig, NULL, bck, &pos);
        SDL_Flip(bck);
        pos.x = data->c * 10;
        pos.y = data->r * 10;
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
            game = 0;
        usleep(25000);
        dig_maze(data);
    }
}

void sdl_display(data_t *data)
{
    SDL_Surface *dig = NULL;
    SDL_Rect pos;
    SDL_Surface *bck = NULL;

    SDL_Init(SDL_INIT_VIDEO);
    pos.x = data->r;
    pos.y = data->c;
    bck = SDL_SetVideoMode(data->x * 10, data->y * 10, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Maze generator graphical version: SDL", NULL);
    dig = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
    SDL_FillRect(bck, NULL, SDL_MapRGB(bck->format, 0, 0, 0));
    SDL_FillRect(dig, NULL, SDL_MapRGB(bck->format, 255, 255, 255));
    game_loop_sdl(data, bck, dig, pos);
    if (data->done == 1)
        sleep(2);
    SDL_FreeSurface(dig);
    SDL_Quit();
}