#include "testobject.hpp"

#include "spritesheet.hpp"

namespace rpg
{

    TestObject::TestObject()
    {
        AddComponent(new rpg::Transform{400, 400});
        AddComponent(new rpg::SpriteRenderer{GetComponent<rpg::Transform>()});

        const Texture2D *texture = rpg::Spritesheet::GetTexture("assets/tilesetA.png");
        GetComponent<rpg::SpriteRenderer>()->AddSprite(new rpg::Sprite{*texture, 64, 128, 16, 16});
    }

} // namespace rpg