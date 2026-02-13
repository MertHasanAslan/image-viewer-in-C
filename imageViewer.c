#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main(){

    SDL_Window* pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, 0);

    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    
    SDL_FillRect(psurface, NULL, 0xFF0000FF);
    SDL_UpdateWindowSurface(pwindow);
    SDL_Delay(3000);




    return 0;
}