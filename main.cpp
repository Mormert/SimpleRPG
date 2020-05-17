#include <iostream>
#include <algorithm>

#include <raylib.h>

#include "object_manager.hpp"
#include "constants.hpp"
#include "spritesheet.hpp"
#include "object.hpp"
#include "scene_loader.hpp"
#include "testobject.hpp"

#include "component.hpp"
#include "components_list"

// Renders the main rendering texture to the screen
// Used in main render loop, after texture mode render
static void RenderMainRenderingTexture(RenderTexture2D &renderTexture, float zoom, int screenHeight, int screenWidth)
{
    // Take the entire render texture into a rectangle
    Rectangle textureRectangle{0.0f, 0.0f, static_cast<float>(renderTexture.texture.width), static_cast<float>(-renderTexture.texture.height)};

    // Using pixels to change the output rectangle size, based on the zoom
    float zoomInPixels{constants::maxZoom * zoom};

    // Take aspect ratio into consideration
    float screenZoomHeightInPixels{zoomInPixels * (static_cast<float>(screenHeight) / static_cast<float>(screenWidth))};

    // Place the enitre render texture rectangle onto this rectangle
    Rectangle screenRectangle{
        0.0f - zoomInPixels / 2.0f,
        0.0f - screenZoomHeightInPixels / 2.0f,
        (screenWidth) + zoomInPixels,
        (screenHeight) + screenZoomHeightInPixels};

    // Draw the render texture onto the screen with the using the new rectangle
    DrawTexturePro(renderTexture.texture, textureRectangle, screenRectangle, Vector2{0.0f, 0.0f}, 0.0f, WHITE);
}

int main()
{

    // SETUP------------------------------------------------------------------------------------------
    int screenWidth{constants::defaultScreenWidth};
    int screenHeight{constants::defualtScreenHeight};
    float screenZoomScroll{0.8f};

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, constants::windowTitle);

    RenderTexture2D renderTexture{LoadRenderTexture(screenWidth, screenHeight)};

    rpg::Spritesheet::AddTexture("assets/tilesetA.png");
    rpg::Spritesheet::AddTexture("assets/tilesetB.png");

    // END SETUP -------------------------------------------------------------------------------------

    //objectManager.AddObject()

    // rpg::TestObject *t{new rpg::TestObject{700, 400}};

    // objectManager.AddObject(t);

    // for (int i = 0; i < 60; i += 1)
    // {
    //     for (int j = 0; j < 60; j += 1)
    //     {
    //         objectManager.AddObject(new rpg::TestObject{i*16, j*16});
    //     }
    // }

    // objectManager.AddObject(new rpg::TestObject{1000, 400});
    // objectManager.AddObject(new rpg::TestObject{950, 400});
    // objectManager.RemoveObject(t);

    rpg::ObjectManager objectManager;
    objectManager.AddObject(new rpg::TestObject{200, 200, 0, 0, 256, 256, "assets/tilesetA.png"});

    rpg::SceneLoader("assets/level.scene", objectManager);

    //rpg::TestObject myTestObject;

    SetTargetFPS(constants::targetFps);

    // GAME LOOP >>
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        // UPDATE ------------------------------------------------------------------------------------
        if (IsWindowResized())
        {
            screenWidth = GetScreenWidth();
            screenHeight = GetScreenHeight();
            UnloadRenderTexture(renderTexture);
            renderTexture = LoadRenderTexture(screenWidth, screenHeight);
        }

        screenZoomScroll += GetMouseWheelMove() * constants::scrollSpeed;
        screenZoomScroll = std::clamp(screenZoomScroll, 0.0f, 1.0f);

        // OBJECT TEST UPDATE >>
        objectManager.Update();
        // <<

        // END UPDATE ---------------------------------------------------------------------------------

        // BEGIN RENDERING TO MAIN RENDER TEXTURE -----------------------------------------------------
        BeginTextureMode(renderTexture);

        ClearBackground(GRAY);

        // OBJECT TEST RENDER >>
        objectManager.Render();
        // <<

        //mySprite.DrawSprite(screenWidth / 2, screenHeight / 2);
        //mySprite2.DrawSprite(screenWidth / 2 + 100, screenHeight / 2);

        EndTextureMode();

        // END RENDERING TO MAIN RENDER TEXTURE -------------------------------------------------------

        // BEGIN SCREEN DRAWING -----------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(WHITE);

        // Use the render texture that was generated, and render it to the screen
        RenderMainRenderingTexture(renderTexture, screenZoomScroll, screenHeight, screenWidth);

        // BEGIN GUI DRAW -----------------------------------------------------------------------------
        DrawText("This is a GUI element", 200, 200, 20, RED);
        DrawFPS(10, 10);
        // END GUI DRAW -------------------------------------------------------------------------------

        EndDrawing();
    } // GAME LOOP END <<

    // DE-INITIALIZATION-------------------------------------------------------------------------------

    rpg::Spritesheet::UnloadSpritesheet();

    CloseWindow();
    // END DE-INITIALIZATION---------------------------------------------------------------------------

    return 0;
}
