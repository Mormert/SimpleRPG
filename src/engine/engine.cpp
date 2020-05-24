#include "object_manager.hpp"
#include "constants.hpp"
#include "spritesheet.hpp"
#include "scene_loader.hpp"
#include "depth_buffer.hpp"
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
    SetWindowIcon(LoadImage(constants::iconFile));
    SetExitKey(0);

    // END SETUP -------------------------------------------------------------------------------------

    rpg::ObjectManager objectManager;
    rpg::SceneLoader(constants::fileLoadPath, objectManager);

    SetTargetFPS(constants::targetFps);

    // GAME LOOP >>
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        // UPDATE ------------------------------------------------------------------------------------

        objectManager.Update();

        // END UPDATE ---------------------------------------------------------------------------------

        // BEGIN SCREEN DRAWING -----------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(WHITE);

        BeginMode2D(rpg::Camera::GetCameraRef());

        objectManager.Render();
        rpg::engine::DepthBuffer::RenderBuffer();
        rpg::engine::DepthBuffer::ClearBuffer();

        EndMode2D();

        // BEGIN GUI DRAW -----------------------------------------------------------------------------
        objectManager.RenderUI();
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
