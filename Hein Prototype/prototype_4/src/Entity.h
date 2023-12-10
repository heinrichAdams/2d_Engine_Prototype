#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL_image.h>

typedef struct
{
    int xPos;
    int yPos;
    SDL_Texture* texture;
} Entity;


#endif