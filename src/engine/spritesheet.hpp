#ifndef SPRITESHEET_HPP
#define SPRITESHEET_HPP

#include <string>
#include <map>

#include <raylib.h>

namespace rpg
{
    class Spritesheet
    {
    private:
        static std::map<std::string, Texture2D> map;
        //Texture2D spriteSheet2DTexture;

    public:
        // Make spritesheet a non-createable object
        Spritesheet() = delete;

        static void AddTexture(std::string textureFileName);

        static const Texture2D &GetTexture(std::string textureName);

        static void UnloadSpritesheet();
    };
} // namespace rpg

#endif // SPRITESHEET_HPP