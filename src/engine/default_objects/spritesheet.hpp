#ifndef SPRITESHEET_HPP
#define SPRITESHEET_HPP

#include "object.hpp"

#include <string>
#include <map>

#include <raylib.h>

namespace rpg::objects
{
    class SpriteSheet : public Object
    {
    private:
        static std::map<std::string, Texture2D> map;

        REGISTER_DEC_TYPE(SpriteSheet);

    public:
        SpriteSheet();

        virtual void ObjectInitFromFile(std::ifstream &fileIn) override;

        static void AddTexture(const std::string &textureFileName);

        static const Texture2D &GetTexture(const std::string &textureName);

        static void UnloadSpriteSheet();
    };
} // namespace rpg::objects

#endif // SPRITESHEET_HPP