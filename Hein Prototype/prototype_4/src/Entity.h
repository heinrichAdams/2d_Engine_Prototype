#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL_image.h>

typedef struct Entity Entity;

struct Entity
{
    int width;
    int height;
    float xPos;
    float yPos;
    float deltaX;
    float deltaY;
    int health;
    int shootDelay;
    SDL_Texture* texture;
    Entity* nextElement;
};


#endif