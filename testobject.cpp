#include "testobject.hpp"

#include "spritesheet.hpp"
#include "object.hpp"

namespace rpg
{

    TestObject::TestObject(int x, int y, int spriteX, int spriteY, int spriteWidth, int spriteHeight, std::string texturePath)
    {
        AddComponents(x, y, spriteX, spriteY, spriteWidth, spriteHeight, texturePath);
    }

    TestObject::TestObject() {}

    void TestObject::ObjectInitFromFile(std::ifstream &fileIn)
    {
        std::cout << "objectinit\n";
        int x, y, spriteX, spriteY, spriteWidth, spriteHeight;
        std::string texturePath;
        fileIn >> x >> y >> spriteX >> spriteY >> spriteWidth >> spriteHeight;
        fileIn >> texturePath;
        AddComponents(x, y, spriteX, spriteY, spriteWidth, spriteHeight, texturePath);
    }

    void TestObject::AddComponents(int x, int y, int spriteX, int spriteY, int spriteWidth, int spriteHeight, std::string texturePath)
    {
        AddComponent(new rpg::Transform{x, y});
        AddComponent(new rpg::SpriteRenderer{GetComponent<rpg::Transform>()});

        GetComponent<rpg::SpriteRenderer>()->AddSprite(new rpg::Sprite{
            rpg::Spritesheet::GetTexture(texturePath.c_str()), spriteX, spriteY, spriteWidth, spriteHeight});
    }

    REGISTER_DEF_TYPE(TestObject);

} // namespace rpg