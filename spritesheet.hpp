#pragma once

#include <raylib.h>

namespace rpg
{
    class Spritesheet
    {
    private:
        Texture2D spriteSheet2DTexture;

    public:
        Spritesheet(const char *fileStr);
        ~Spritesheet();

        const Texture2D &GetTexture();
    };
} // namespace rpg
