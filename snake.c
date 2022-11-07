#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#include "snake.h"
#include <stdlib.h>
#define TAILLE 20


void snake_up(snake * snake,int *a,int *b){
    int c=(snake->tab)[(snake->a)*2-2];
    int d=(snake->tab)[(snake->a)*2-1];
    if(*a !=c || *b !=d){
        for(int i=0;i< snake->a -1 ;i++){
            (snake->tab)[2*i]=border((snake->tab)[2*i+2] )%20;
            (snake->tab)[2*i+1]=border((snake->tab)[2*i+3])%20;
        }
        (snake->tab)[(snake->a)*2 - 2]=border(c-1) %20;
        (snake->tab)[(snake->a)*2 - 1]=border(d) %20;
    }else{
        (snake->tab)[(snake->a)*2]=border(c-1)%20;
        (snake->tab)[(snake->a)*2 +1]=border(d)%20;
        (snake->a)++;
        *a = rand() % 20;*b= rand() % 20;
    }
    
}
void snake_down(snake * snake,int *a,int *b){
    int c=(snake->tab)[(snake->a)*2-2];
    int d=(snake->tab)[(snake->a)*2-1];
    if(*a !=c || *b !=d){
        for(int i=0;i< snake->a -1;i++){
            (snake->tab)[2*i]=border((snake->tab)[2*i+2] )%20;
            (snake->tab)[2*i+1]=border((snake->tab)[2*i+3] )%20 ;
        }
        (snake->tab)[(snake->a)*2 -2]=border(c+1 )%20;
        (snake->tab)[(snake->a)*2 -1]=border(d)%20;
        
    }else{
        (snake->tab)[(snake->a)*2]=border(c+1) %20;
        (snake->tab)[(snake->a)*2 +1]=border(d) %20;
        (snake->a)++;
        *a = rand() % 20;*b= rand() % 20;
    }
    
    
}
void snake_r(snake * snake,int *a,int *b){
    int c=(snake->tab)[(snake->a)*2-2] ;
    int d=(snake->tab)[(snake->a)*2-1];
    if(*a !=c || *b !=d){
        for(int i=0;i< snake->a -1 ;i++){
            (snake->tab)[2*i]=border((snake->tab)[2*i+2])%20;
            (snake->tab)[2*i+1]=border((snake->tab)[2*i+3])%20;
        }
        (snake->tab)[(snake->a)*2-2]=border(c) %20;
        (snake->tab)[(snake->a)*2 -1]=border(d+1) %20;
    }else{
        (snake->tab)[(snake->a)*2]=border(c )%20;
        (snake->tab)[(snake->a)*2 +1]=border(d+1) %20;
        (snake->a)++;
        *a = rand() % 20;*b= rand() % 20;
    }
    
}
void snake_l(snake * snake,int *a,int *b){
    int c=(snake->tab)[(snake->a)*2-2];
    int d=(snake->tab)[(snake->a)*2-1];
    if( *a != c || *b != d){
        for(int i=0;i< snake->a -1;i++){
            (snake->tab)[2*i]=border((snake->tab)[2*i+2]) %20;
            (snake->tab)[2*i+1]=border((snake->tab)[2*i+3]) %20;
        }
        (snake->tab)[(snake->a)*2 -2]=border(c) %20;
        (snake->tab)[(snake->a)*2 -1]=border(d-1) %20;
        
    }else{
        (snake->tab)[(snake->a)*2]=border(c) %20;
        (snake->tab)[(snake->a)*2 +1]=border(d-1) %20;
        (snake->a)++;
        *a = rand() % 20;*b= rand() % 20;
    }
}
void afficher_snake(snake * snake , SDL_Window   * window , SDL_Renderer *renderer,int a,int b){
    SDL_Rect rect;
    /* couleur de fond */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    for(int i=0;i< snake->a ; i++){
        /* dessiner en blanc */
            SDL_SetRenderDrawColor(renderer,0 , i*60 % 250, 250, 0);
            rect.x = (1000/TAILLE)*((snake->tab)[2*i+1]);
            rect.y = (1000/TAILLE)*((snake->tab)[2*i]);
            rect.w = rect.h = 1000/TAILLE;
            SDL_RenderFillRect(renderer, &rect );
            /* afficher à l'ecran */
            SDL_RenderPresent(renderer);
    }
    /* dessiner en blanc */
            SDL_SetRenderDrawColor(renderer, 255, 250,250, 230);
            rect.x = (1000/TAILLE)*b;
            rect.y = (1000/TAILLE)*a;
            rect.w = rect.h = 1000/TAILLE;
            SDL_RenderFillRect(renderer, &rect );
            /* afficher à l'ecran */
            SDL_RenderPresent(renderer);
}

int border(int a){
    if( 0>a ){
        a=20+a;
    }
    return a;
}