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
    for (int x = 0; x <= 900; x++){
        for (int y = 0; y <= 600; y++){
            SDL_Rect rect = (SDL_Rect){.x=x, .y=y, .h=1, .w=1};
            SDL_FillRect(psurface, &rect, color);
        }
    }
    SDL_UpdateWindowSurface(pwindow);
    SDL_Delay(5000);



    return 0;
}