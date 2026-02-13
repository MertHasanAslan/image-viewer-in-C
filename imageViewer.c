#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main(){


    printf("Hello World! \n");
    SDL_Window* pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, 0);
    SDL_Delay(3000);

    return 0;
}