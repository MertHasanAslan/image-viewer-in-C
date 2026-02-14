#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>


int main(){
    // getting filename
    printf("Please enter the filename (only ppm files): ");
    char filename[255];
    if (fgets(filename, sizeof(filename), stdin) == NULL){
        printf("could not get the filename");
        return 1;
    }
    filename[strcspn(filename, "\n")] = '\0';

    // Opening file
    FILE* pfile = fopen(filename, "r");
    if(pfile == NULL){
        perror("File could not open");
        return 1;
    }

    // reading first two lines (specifier and comment)
    char line[1024];
    for (int i = 0; i < 2; i++){
        fgets(line, sizeof(line), pfile);
        printf("%s", line);
    }
    
    // getting width and height values
    int width, height;
    fscanf(pfile, "%d %d\n", &width, &height);

    // reading max color value line
    fgets(line, sizeof(line), pfile);




    SDL_Window* pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    
    
    Uint8 r, g, b;
    unsigned int tempr, tempg, tempb;
    Uint32 color;
    
    SDL_Rect rect = (SDL_Rect){.x=0, .y=0, .h=1, .w=1};
    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            rect.x = x;
            rect.y = y;
            fscanf(pfile, "%u %u %u", &tempr, &tempg, &tempb);
            if (tempr > 255 || tempg > 255 || tempb > 255) {
                printf("An error occurred while reading rgb values");
                return 1;
            }
            r = (Uint8)tempr;
            g = (Uint8)tempg;
            b = (Uint8)tempb;
            color = SDL_MapRGB(psurface->format, r, g, b);
            SDL_FillRect(psurface, &rect, color);
        }
    }
    SDL_UpdateWindowSurface(pwindow);
    SDL_Delay(5000);



    return 0;
}