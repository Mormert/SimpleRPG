#include "testobject.hpp"

#include "spritesheet.hpp"
#include "object.hpp"
#include "transform.hpp"
#include "sprite_renderer.hpp"
#include "sprite.hpp"

namespace rpg::objects
{

    TestObject::TestObject(int x, int y, int spriteX, int spriteY, int spriteWidth, int spriteHeight, std::string texturePath)
    {
        AddComponents(x, y, spriteX, spriteY, spriteWidth, spriteHeight, texturePath);
    }

    TestObject::TestObject() {}

    void TestObject::ObjectInitFromFile(std::ifstream &fileIn)
    {
        std::string texturePath;
        int x, y, spriteX, spriteY, spriteWidth, spriteHeight;
        fileIn >> x >> y >> spriteX >> spriteY >> spriteWidth >> spriteHeight >> texturePath;
        AddComponents(x, y, spriteX, spriteY, spriteWidth, spriteHeight, texturePath);
    }

    void TestObject::AddComponents(int x, int y, int spriteX, int spriteY, int spriteWidth, int spriteHeight, std::string texturePath)
    {
        AddComponent(new rpg::components::Transform{x, y});
        AddComponent(new rpg::components::SpriteRenderer{GetComponent<rpg::components::Transform>()});

        GetComponent<rpg::components::SpriteRenderer>()->AddSprite(new rpg::Sprite{
            rpg::objects::SpriteSheet::GetTexture(texturePath.c_str()), spriteX, spriteY, spriteWidth, spriteHeight});
    }

    REGISTER_DEF_TYPE(TestObject);

} // namespace rpg