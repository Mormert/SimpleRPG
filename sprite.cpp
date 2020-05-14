#include "sprite.hpp"

#include <raylib.h>

#include <iostream>

namespace rpg
{

    Sprite::Sprite(Spritesheet &spriteSheet, float x, float y,
                   float width, float heigth,
                   Vector2 origin) : m_spriteRectangle{x, y, width, heigth},
                                     m_spriteSheetTexture{spriteSheet.GetTexture()},
                                     m_spriteOrigin{origin}
    {
    }

    // TODO : Add scale parameter
    void Sprite::DrawSprite(int x, int y, float rotation, Color color)
    {
        Rectangle destinationRectangle{static_cast<float>(x), static_cast<float>(y),
                                       m_spriteRectangle.width, m_spriteRectangle.height};

        DrawTexturePro(m_spriteSheetTexture, m_spriteRectangle, destinationRectangle,
                       m_spriteOrigin, rotation, color);
    }

    void Sprite::SetOrigin(Vector2 newOrigin)
    {
        m_spriteOrigin = newOrigin;
    }

    Sprite::~Sprite()
    {
        std::cout << "Calling ~Sprite()" << std::endl;
    }


} // namespace rpg