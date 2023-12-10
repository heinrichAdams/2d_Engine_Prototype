#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL_image.h>

void UpdateBackBuffer(void);
void UpdateFrontBuffer(void);
SDL_Texture* LoadTextureFromFile(char* filePath);
void DrawTexture(SDL_Texture* texture, int xPos, int yPos);

#endif