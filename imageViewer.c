#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main(){

    SDL_Window* pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, 0);

    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    
    
    Uint8 r, g, b;
    r = 0xBA;
    g = 0x82;
    b = 0x80;
    Uint32 color = SDL_MapRGB(psurface->format, r, g, b);
    SDL_Rect* prect = malloc(sizeof *prect);
    if (prect!=NULL){
        *prect = (SDL_Rect){.x=450-100/2, .y=300-100/2, .w=100, .h=100};
    }
    SDL_FillRect(psurface, prect, color);
    SDL_UpdateWindowSurface(pwindow);
    SDL_Delay(5000);



    free(prect);
    return 0;
}