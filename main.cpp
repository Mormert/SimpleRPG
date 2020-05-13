#include <iostream>
#include <algorithm>

#include <raylib.h>

#include "constants.hpp"
#include "spritesheet.hpp"
#include "sprite.hpp"

int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth{constants::defaultScreenWidth};
    int screenHeight{constants::defualtScreenHeight};
    float screenZoomScroll{0.8f};

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, constants::windowTitle);

    Texture2D texture{LoadTexture("assets/tilesetA.png")};

    //Rectangle textRecSrc{0, 0, 256, 256};
    //Rectangle textRecDest{200, 200, static_cast<float>(800.0f), static_cast<float>(800.0f)};

    RenderTexture2D renderTexture{LoadRenderTexture(screenWidth, screenHeight)};

    // rpg::Spritesheet sheetA{"assets/tilesetA.png"};
    // rpg::Spritesheet sheetB{"assets/tilesetB.png"};

    // rpg::Sprite mySprite(sheetA, 32, 32, 200, 200);

    SetTargetFPS(constants::targetFps);
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        if (IsWindowResized())
        {
            screenWidth = GetScreenWidth();
            screenHeight = GetScreenHeight();
            //textRecDest = {0, 0, static_cast<float>(screenWidth), static_cast<float>(screenHeight)};
            UnloadRenderTexture(renderTexture);
            renderTexture = LoadRenderTexture(screenWidth, screenHeight);
        }

        screenZoomScroll += GetMouseWheelMove() * constants::scrollSpeed;
        screenZoomScroll = std::clamp(screenZoomScroll, 0.0f, 1.0f);

        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        BeginTextureMode(renderTexture);

        ClearBackground(GRAY); // Clear texture background

        //DrawTexture(texture, screenWidth - texture.width - 60, screenHeight / 2 - texture.height / 2, WHITE);
        //DrawTexturePro(texture, textRecSrc, textRecDest, Vector2{0.0f, 0.0f}, 0.0f, WHITE);
        DrawTexture(texture, screenWidth/2.0f, screenHeight/2.0f, WHITE);

        EndTextureMode();

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(WHITE);

        // Use the render texture that was generated, and apply zoom features

        // Take the entire render texture into a rectangle
        Rectangle textureRectangle{0.0f, 0.0f, static_cast<float>(renderTexture.texture.width), static_cast<float>(-renderTexture.texture.height)};

        float zoomInPixels{constants::maxZoom * screenZoomScroll};

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

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
