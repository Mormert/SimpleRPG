#include "spritesheet.hpp"

#include <raylib.h>

#include <iostream>

namespace rpg::objects
{
    std::map<std::string, Texture2D> SpriteSheet::map;

    SpriteSheet::SpriteSheet() {}

    void SpriteSheet::ObjectInitFromFile(std::ifstream &fileIn)
    {
        std::string textureName;
        fileIn >> textureName;

        AddTexture(textureName);
    }

    void SpriteSheet::AddTexture(const std::string &textureFileName)
    {
        if (!map.count(textureFileName)) // Does the map not already contain the texture?
        {
            Texture2D texture{LoadTexture(textureFileName.c_str())};
            map.insert(std::pair<std::string, Texture2D>(textureFileName, texture));
        }
    }

    const Texture2D &SpriteSheet::GetTexture(const std::string &textureName)
    {
        return map.at(textureName);
    }

    void SpriteSheet::UnloadSpriteSheet()
    {
        for (auto &x : map)
        {
            UnloadTexture(x.second);
        }
    }

    REGISTER_DEF_TYPE(SpriteSheet);

} // namespace rpg::objects