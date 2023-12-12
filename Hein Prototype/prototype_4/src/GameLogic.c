#include "GameLogic.h"
#include "Game.h"
#include "Entity.h"
#include "Window.h"
#include "Display.h"
#include "Config.h"

// Static Function Prototypes
// ---------------------------------------------
static void Update(void);
static void RenderGameObjects(void);
static void InitializePlayer(void);
static void ShootProjectile(void);
static void PlayerLogic(void);
static void ProjectileLogic(void);
static void RenderPlayer(void);
static void RenderProjectiles(void);

// ---------------------------------------------


// External Data Structures
// ---------------------------------------------
extern Window window;
extern Game game;
// ---------------------------------------------

// Global Variables
// ---------------------------------------------
static Entity* player;
static SDL_Texture* projectileTexture;
// ---------------------------------------------


void InitializeGame(void)
{
    
    window.send.Update = Update;
    window.send.RenderGameObjects = RenderGameObjects;

    memset(&game, 0, sizeof(Game));
    game.actorEnd = &game.actorRoot;
    game.projectileEnd = &game.projectileRoot;

    InitializePlayer();

    projectileTexture = LoadTextureFromFile("assets/playerBullet.png");

}

static void InitializePlayer(void)
{
    player = malloc(sizeof(Entity));
    memset(player, 0, sizeof(Entity));

    game.actorEnd->nextElement = player;
    game.actorEnd = player;

    player->xPos = 500;
    player->yPos = 500;
    player->texture = LoadTextureFromFile("assets/player.png");
    SDL_QueryTexture(player->texture, NULL, NULL, &player->width, &player->height);

}

static void Update(void)
{
    PlayerLogic();
    ProjectileLogic();
}

static void RenderGameObjects(void)
{
    RenderPlayer();
    RenderProjectiles();
}

static void ShootProjectile(void)
{

    Entity* projectile;
    projectile = malloc(sizeof(Entity));
    memset(projectile, 0, sizeof(Entity));

    game.projectileEnd->nextElement = projectile;
    game.projectileEnd = projectile;

    projectile->xPos = player->xPos;
    projectile->yPos = player->yPos;

    projectile->deltaX = PLAYER_PROJECTILE_SPEED;
    projectile->deltaY = 0;

    projectile->health = 1;

    projectile->texture = projectileTexture;

    SDL_QueryTexture(projectile->texture, NULL, NULL, &projectile->width, &projectile->height);

    // Centre Projectile
    projectile->yPos += (player->height/2) - (projectile->height/2);

    player->shootDelay = 5;

}

static void PlayerLogic(void)
{
    player->deltaX = 0;
    player->deltaY = 0;

    // Delay Shoot Projectile
    if(player->shootDelay > 0)
    {
        player->shootDelay--;
    }

    // User Input (Movement)
    if(window.keys[SDL_SCANCODE_W])
    {
        player->deltaY -= PLAYER_SPEED;
    }
    if(window.keys[SDL_SCANCODE_S])
    {
        player->deltaY += PLAYER_SPEED;
    }
    if(window.keys[SDL_SCANCODE_A])
    {
        player->deltaX -= PLAYER_SPEED;
    }
    if(window.keys[SDL_SCANCODE_D])
    {
        player->deltaX += PLAYER_SPEED;
    }

    // User Input (Shoot Projectile)
    if(window.keys[SDL_SCANCODE_SPACE] && player->shootDelay == 0)
    {
        ShootProjectile();
    }

    player->xPos += player->deltaX;
    player->yPos += player->deltaY;

}

static void ProjectileLogic(void)
{
    Entity* currentProjectile;
    Entity* previousProjectile;

    previousProjectile = &game.projectileRoot;

    for(currentProjectile = game.projectileRoot.nextElement;
    currentProjectile != NULL;
    currentProjectile = currentProjectile->nextElement)
    {
        currentProjectile->xPos += currentProjectile->deltaX;
        currentProjectile->yPos += currentProjectile->deltaY;

        if(currentProjectile->xPos > WINDOW_WIDTH)
        {
            if(currentProjectile == game.projectileEnd)
            {
                game.projectileEnd = previousProjectile;
            }

            previousProjectile->nextElement = currentProjectile->nextElement;
            free(currentProjectile);
            currentProjectile = previousProjectile;
        }

        previousProjectile = currentProjectile;
    }

}

static void RenderPlayer(void)
{
    DrawTexture(player->texture, player->xPos, player->yPos);

}

static void RenderProjectiles(void)
{
    Entity* currentProjectile;
    for(currentProjectile = game.projectileRoot.nextElement;
    currentProjectile != NULL;
    currentProjectile = currentProjectile->nextElement)
    {
        DrawTexture(currentProjectile->texture, 
        currentProjectile->xPos, 
        currentProjectile->yPos);
    }
}