#ifndef GAME_H
#define GAME_H

#include "Entity.h"

typedef struct
{
    Entity actorRoot, *actorEnd;
    Entity projectileRoot, *projectileEnd;
}Game;


#endif