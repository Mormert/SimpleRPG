#include "spritesheet.hpp"

#include <raylib.h>

#include <iostream>

namespace rpg
{
    std::map<std::string, Texture2D> Spritesheet::map;

    void Spritesheet::AddTexture(std::string textureFileName)
    {
        if (!map.count(textureFileName)) // Does the map not already contain the texture?
        {
            Texture2D texture{LoadTexture(textureFileName.c_str())};
            map.insert(std::pair<std::string, Texture2D>(textureFileName, texture));
        }
    }

    const Texture2D &Spritesheet::GetTexture(std::string textureName)
    {
        std::cout << "Getting texture with id: " << map.at(textureName).id << '\n';
        return map.at(textureName);
    }

    void Spritesheet::UnloadSpritesheet()
    {
        for (auto &x : map)
        {
            UnloadTexture(x.second);
        }
    }

} // namespace rpg