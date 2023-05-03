#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_audio.h>

using namespace std;

SDL_Surface* image = NULL;
SDL_Texture* texture = NULL;

void Show_image(SDL_Renderer* renderer, const char* str_image, SDL_Rect rect)
{
    IMG_Init(IMG_INIT_PNG);
    image = IMG_Load(str_image);
    if (image == NULL)
    {
        cerr << "Unable to load image!" << str_image << endl
            << "SDL Error: " << SDL_GetError();
    }
    else
    {
        texture = SDL_CreateTextureFromSurface(renderer, image);
        SDL_RenderCopy(renderer, texture, NULL, &rect);
        SDL_RenderPresent(renderer);
        SDL_FreeSurface(image);
    }
    SDL_DestroyTexture(texture);
    texture = NULL;
    IMG_Quit();
}