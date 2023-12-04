#include <iostream>
#include "Game.h"

int main(int argc, char* argv[]) 
{

    // 1

    // <<< INITIALIZATION
    
    Game game;
    game.Initialize();

    // INITIALIZATION >>>

    // 2

    // <<< PROCESS LOOP
    
    game.Run();

    // PROCESS LOOP >>>
    
    // 3

    // <<< END PROCESS

    game.Exit();

    // END PROCESS >>>

    return 0;
}