#include "spritesheet.hpp"

#include <raylib.h>

namespace rpg
{

    Spritesheet::Spritesheet(const char *fileStr)
        : spriteSheet2DTexture{LoadTexture(fileStr)} {}

    Spritesheet::~Spritesheet()
    {
        UnloadTexture(spriteSheet2DTexture);
    }

    const Texture2D &Spritesheet::GetTexture()
    {
        return spriteSheet2DTexture;
    }

} // namespace rpg