#include "testobject.hpp"

#include "spritesheet.hpp"
#include "object.hpp"

namespace rpg
{

    TestObject::TestObject(int x, int y, int spriteX, int spriteY, int spriteWidth, int spriteHeight, std::string texturePath)
    {
        AddComponent(new rpg::Transform{x, y});
        AddComponent(new rpg::SpriteRenderer{GetComponent<rpg::Transform>()});

        GetComponent<rpg::SpriteRenderer>()->AddSprite(new rpg::Sprite{
            rpg::Spritesheet::GetTexture(texturePath.c_str()), spriteX, spriteY, spriteWidth, spriteHeight});
    }

    TestObject::TestObject()
    {
        std::cout << "Created test obj\n";
    }

    REGISTER_DEF_TYPE(TestObject);

} // namespace rpg