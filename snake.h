#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#define TAILLE 20
#include <SDL2/SDL.h>

#include <time.h>

#include <stdlib.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>

typedef struct snake{
    int a;
    int *tab;
}snake;

void snake_up(snake * snake,int *a,int *b);
void snake_down(snake * snake,int *a,int *b);
void snake_r(snake * snake,int *a,int *b);
void snake_l(snake * snake,int *a,int *b);
void afficher_snake(snake * snake , SDL_Window   * window , SDL_Renderer *renderer,int a,int b);
int border(int a);
#endif