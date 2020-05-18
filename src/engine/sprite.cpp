#include "sprite.hpp"

#include <raylib.h>

#include <iostream>

namespace rpg
{

    Sprite::Sprite(const Texture2D &texture, int x, int y,
                   int width, int heigth,
                   Vector2 origin) : m_spriteRectangle{
                                         static_cast<float>(x), static_cast<float>(y),
                                         static_cast<float>(width), static_cast<float>(heigth)},
                                     m_spriteSheetTexture{texture}, m_spriteOrigin{origin}
    {
    }

    // TODO : Add scale parameter
    void Sprite::DrawSprite(int x, int y, float rotation, Color color)
    {
        Rectangle destinationRectangle{static_cast<float>(x), static_cast<float>(y),
                                       m_spriteRectangle.width, m_spriteRectangle.height};

        // TODO : Frustum culling
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