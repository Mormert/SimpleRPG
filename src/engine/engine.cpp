#include "object_manager.hpp"
#include "constants.hpp"
#include "spritesheet.hpp"
#include "scene_loader.hpp"
#include "camera.hpp"

#include <raylib.h>

#include <iostream>
#include <algorithm>

int main()
{

    // SETUP------------------------------------------------------------------------------------------
    int screenWidth{constants::defaultScreenWidth};
    int screenHeight{constants::defualtScreenHeight};

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, constants::windowTitle);

    // END SETUP -------------------------------------------------------------------------------------

    rpg::Camera::SetZoom(1.0f);
    rpg::Camera::SetOffset(screenWidth / 2, screenHeight / 2);
    rpg::Camera::SetTarget(0.0f, 0.0f);
    

    rpg::ObjectManager objectManager;
    rpg::SceneLoader(constants::fileLoadPath, objectManager);

    SetTargetFPS(constants::targetFps);

    // GAME LOOP >>
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        // UPDATE ------------------------------------------------------------------------------------
        if (IsWindowResized())
        {
            screenWidth = GetScreenWidth();
            screenHeight = GetScreenHeight();
            rpg::Camera::SetOffset(screenWidth / 2, screenHeight / 2);
            rpg::Camera::SetTarget(0.0f, 0.0f);
        }

        objectManager.Update();

        // END UPDATE ---------------------------------------------------------------------------------

        // BEGIN SCREEN DRAWING -----------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GRAY);

        BeginMode2D(rpg::Camera::GetCameraRef());

        objectManager.Render();

        EndMode2D();

        // BEGIN GUI DRAW -----------------------------------------------------------------------------
        DrawText("This is a GUI element", 200, 200, 20, RED);
        DrawFPS(10, 10);
        // END GUI DRAW -------------------------------------------------------------------------------

        EndDrawing();
    } // GAME LOOP END <<

    // DE-INITIALIZATION-------------------------------------------------------------------------------

    rpg::objects::SpriteSheet::UnloadSpriteSheet();

    CloseWindow();
    // END DE-INITIALIZATION---------------------------------------------------------------------------

    return 0;
}
