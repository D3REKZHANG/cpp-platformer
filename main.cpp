#include "include/raylib.h"
#include "include/statemanager.h"
#include "include/menu.h"

int main(){

    const int screenWidth = 800;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "window");

    SetTargetFPS(10);

    StateManager stateManager;

    stateManager.pushState(Menu::instance());

    // main game loop
    while (!WindowShouldClose() && stateManager.running())
    {
        // handle events (key presses, mouse, etc)
        stateManager.handleEvents();

        // update
        stateManager.update();

        // draw
        BeginDrawing();
            stateManager.draw();
        EndDrawing();
    }

    CloseWindow();
    stateManager.cleanup();

    return 0;
}
