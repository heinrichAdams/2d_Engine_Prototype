#include "GameLogic.h"
#include "Entity.h"
#include "Window.h"
#include "Display.h"
#include "Config.h"


extern Window window;
extern Entity player;
extern Entity projectile;

static void ProcessPlayer(void)
{
    player.xPos += player.deltaX;
    player.yPos += player.deltaY;

    // User Input (Movement)
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

    // User Input (Shoot Projectile)
    if(window.shoot && projectile.health == 0)
    {
        projectile.xPos = player.xPos;
        projectile.yPos = player.yPos;
        projectile.deltaX = 16;
        projectile.deltaY = 0;
        projectile.health = 1;
    }

    // Add Transform To Projectile
    projectile.xPos += projectile.deltaX;
    projectile.yPos += projectile.deltaY;

    // Destroy Projectile When it Reaches The Edge Of The Screen
    if(projectile.xPos > WINDOW_WIDTH)
    {
        projectile.health = 0;
    }

    // Draw Player 
    DrawTexture(player.texture, player.xPos, player.yPos);

    // Draw Projectile
    DrawTexture(projectile.texture, projectile.xPos, projectile.yPos);


}

void UpdateGame(void)
{
    ProcessPlayer();
}

