#pragma once

#include <raylib.h>

#include <string>


namespace rpg
{
    class Spritesheet
    {

    private:
        

    public:
        Texture2D spriteSheet2DTexture;

        Spritesheet(const std::string &spriteSheetFile) : spriteSheet2DTexture{LoadTexture(spriteSheetFile.c_str())}
        {
        }

        ~Spritesheet()
        {
            UnloadTexture(spriteSheet2DTexture);
        }

        const Texture2D &GetTexture()
        {
            return spriteSheet2DTexture;
        }
    };
} // namespace rpg
