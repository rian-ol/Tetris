#include <raylib.h>
#include "game.h"

double lastUpdateTime = 0;

bool eventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    Color darkBlue = { 44,44,127,255};
    InitWindow(1000,1000,"title");
    SetTargetFPS(60);

    Game game = Game();

    while(WindowShouldClose() == false)
    {
        game.HandleInput();

        if(eventTriggered(0.2)){
            game.MoveBlockDown();
        }
        
        
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}