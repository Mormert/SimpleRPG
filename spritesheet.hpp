#pragma once

#include <raylib.h>

namespace rpg
{
    class Spritesheet
    {
    private:
        Texture2D spriteSheet2DTexture;

    public:
        Spritesheet(const char *fileStr) : spriteSheet2DTexture{LoadTexture(fileStr)} {}
        ~Spritesheet() { UnloadTexture(spriteSheet2DTexture); }

        const Texture2D &GetTexture()
        {
            return spriteSheet2DTexture;
        }
    };
} // namespace rpg
