#include "sprite.hpp"
#include "depth_buffer.hpp"

#include <raylib.h>

#include <iostream>
#include <cmath>

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
                                       std::abs(m_spriteRectangle.width), std::abs(m_spriteRectangle.height)};

        engine::DepthBuffer::DrawTextureProDepth(m_depth,
                                                 m_spriteSheetTexture,
                                                 Rectangle{m_spriteRectangle.x, m_spriteRectangle.y, m_spriteRectangle.width * m_verticalFlip, m_spriteRectangle.height * m_horizontalFlip},
                                                 destinationRectangle,
                                                 m_spriteOrigin,
                                                 rotation,
                                                 color);
    }

    void Sprite::DrawSpriteDirect(int x, int y, float rotation, Color color)
    {
        Rectangle destinationRectangle{static_cast<float>(x), static_cast<float>(y),
                                       std::abs(m_spriteRectangle.width), std::abs(m_spriteRectangle.height)};
        DrawTexturePro(m_spriteSheetTexture,
                       Rectangle{m_spriteRectangle.x, m_spriteRectangle.y, m_spriteRectangle.width * m_verticalFlip, m_spriteRectangle.height * m_horizontalFlip},
                       destinationRectangle,
                       m_spriteOrigin,
                       rotation,
                       color);
    }

    void Sprite::SetDepth(int depth)
    {
        m_depth = depth;
    }

    int Sprite::GetDepth()
    {
        return m_depth;
    }

    void Sprite::SetFlipVertical(bool setFlip)
    {
        if (setFlip)
        {
            m_verticalFlip = -1;
        }
        else
        {
            m_verticalFlip = 1;
        }
    }

    void Sprite::SetFlipHorizontal(bool setFlip)
    {
        if (setFlip)
        {
            m_horizontalFlip = -1;
        }
        else
        {
            m_horizontalFlip = 1;
        }
    }

    bool Sprite::IsFlippedVertical()
    {
        return m_verticalFlip == -1;
    }

    bool Sprite::IsFlippedHorizontal()
    {
        return m_horizontalFlip == -1;
    }

    void Sprite::SetOrigin(Vector2 newOrigin)
    {
        m_spriteOrigin = newOrigin;
    }

    Sprite::~Sprite() {}

} // namespace rpg