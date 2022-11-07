#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include "snake.h"
#define TAILLE 20

int main(){


    snake * snake=malloc(sizeof(snake));
    (snake->tab)=malloc(sizeof(int)*10000);
    

    
    
    
    
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window   * window;
    window = SDL_CreateWindow("SDL2 Programme 0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_RESIZABLE);
    
    SDL_Renderer *renderer; //Initialisation of the renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED ); //Creat the renderer
    int p=1,i=0;
    int p1 = rand() % 20,p2= rand() % 20;
    

    int o=1;
    while(p && o){
        snake->a=1;
        (snake->tab)[0]=5;
        (snake->tab)[1]=5;
        int up=0,d=0,r=1,l=0;
        //Creat the surface
        SDL_Surface *tmp = NULL; 
	    SDL_Texture *texture = NULL;    //Creat the texture
	    tmp = SDL_LoadBMP("start.bmp");  //télechargement de l'image 
	

    
	    texture = SDL_CreateTextureFromSurface(renderer, tmp); //put the image on the texture
	    SDL_RenderCopy(renderer, texture, NULL, NULL); //put the texture on the rendrer
	    SDL_RenderPresent(renderer); // show the render on the window (scren)
        int p=1,e=1;
        SDL_Event event; // Creat  the variabele Event  
	    while(e && p){
            if (SDL_PollEvent(&event)){                 
                switch(event.type){  // the cases of the events
                    case SDL_MOUSEBUTTONDOWN : e=0;break; // if we click the right button
                    case SDL_QUIT : p = 0;e=0;  break; // if we cilck the X button
                    default: break;
                }
            }
        }
        while(p){
            int snk=100000;
            SDL_Event event;
            
            if( i<snk || SDL_PollEvent(&event) ){
                if(event.type == SDL_KEYDOWN){
                    switch(event.key.keysym.sym){
                        case SDLK_UP :if(r || l){snake_up(snake,&p1,&p2);up=1;d=0;l=0;r=0;i=snk;};break; 
                        case SDLK_DOWN :if(r || l){snake_down(snake,&p1,&p2);up=0;d=1;l=0;r=0;i=snk;};break;
                        case SDLK_RIGHT : if(up || d){snake_r(snake,&p1,&p2);up=0;d=0;l=0;r=1;i=snk;};break;
                        case SDLK_LEFT : if(up || d){snake_l(snake,&p1,&p2);up=0;d=0;l=1;r=0;i=snk;};break;
                        default: break;
                    }
                    
                }
                if(SDL_PollEvent(&event)){
                    switch(event.type){  // the cases of the events
                        case SDL_QUIT : p = 0;  break; // if we cilck the X button
                        default: break;
                    }
                }
                i++;
                
            }else{
                if(up) snake_up(snake,&p1,&p2);
                if(l) snake_l(snake,&p1,&p2);
                if(d) snake_down(snake,&p1,&p2);
                if(r) snake_r(snake,&p1,&p2);
                i=0;
            
                afficher_snake(snake ,window,renderer,p1,p2);
            
            }
            
            
            
        }
    

        if(snake->a <20){
            tmp = SDL_LoadBMP("youwin.bmp"); // downlod the image
	

	        texture = SDL_CreateTextureFromSurface(renderer, tmp); //put the image on the texture
	        SDL_RenderCopy(renderer, texture, NULL, NULL); // put the texture on the renderer 
	        SDL_RenderPresent(renderer); //show the renderer on the scren
            p=1;
            while(p){
                if(SDL_PollEvent(&event)){
                    switch(event.type){
                        case SDL_MOUSEBUTTONDOWN : p=0;break;
                        case SDL_QUIT : p=0;o=0;SDL_DestroyWindow(window);break;
                        default : break;
                    }
                }
            }
        

        }else{
            tmp = SDL_LoadBMP("youlose.bmp");
	

	        texture = SDL_CreateTextureFromSurface(renderer, tmp);
	        SDL_RenderCopy(renderer, texture, NULL, NULL);
	        SDL_RenderPresent(renderer);
            p=1;
            while(p){
                if(SDL_PollEvent(&event)){
                    switch(event.type){
                        case SDL_MOUSEBUTTONDOWN : p=0;break;
                        case SDL_QUIT :p=0;o=0;SDL_DestroyWindow(window);break;
                        default : break;
                    }
                }
            }
        }
        SDL_FreeSurface(tmp);

        
         
        
    }


    return 0;
}
