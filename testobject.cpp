#include "testobject.hpp"

#include "spritesheet.hpp"

namespace rpg
{

    TestObject::TestObject()
    {
        AddComponent(new rpg::Transform{400, 400});
        AddComponent(new rpg::SpriteRenderer{GetComponent<rpg::Transform>()});

        GetComponent<rpg::SpriteRenderer>()->AddSprite(new rpg::Sprite{
            rpg::Spritesheet::GetTexture("assets/tilesetA.png"), 64, 128, 16, 16});
    }

} // namespace rpg