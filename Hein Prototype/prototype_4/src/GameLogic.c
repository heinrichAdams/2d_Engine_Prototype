#include "GameLogic.h"
#include "Entity.h"
#include "Window.h"

extern Window window;
extern Entity player;

static void MovePlayer(void)
{
    if(window.up)
    {
        player.yPos -= 5;
    }
    if(window.down)
    {
        player.yPos += 5;
    }
    if(window.left)
    {
        player.xPos -= 5;
    }
    if(window.right)
    {
        player.xPos += 5;
    }
}

void UpdateGame(void)
{
    MovePlayer();
}

