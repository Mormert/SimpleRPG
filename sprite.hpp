#pragma once

#include <raylib.h>

#include "spritesheet.hpp"
#include "component.hpp"
#include "object.hpp"

namespace rpg
{
    class Sprite : public IComponent
    {
    private:
        const Rectangle m_spriteRectangle;     // The bounds of this sprite on
        const Texture2D &m_spriteSheetTexture; // the spritesheet texture

        Vector2 m_spriteOrigin;

    public:
        Sprite(Spritesheet &spriteSheet, float x, float y,
               float width, float heigth, Vector2 origin = {0.0f, 0.0f}) : m_spriteRectangle{x, y, width, heigth},
                                                                           m_spriteSheetTexture{spriteSheet.GetTexture()},
                                                                           m_spriteOrigin{origin}
        {
        }

        void DrawSprite(int x, int y, float rotation = 0.0f, Color color = WHITE)
        {
            Rectangle destinationRectangle{static_cast<float>(x), static_cast<float>(y), m_spriteRectangle.width, m_spriteRectangle.height};
            DrawTexturePro(m_spriteSheetTexture, m_spriteRectangle, destinationRectangle, m_spriteOrigin, rotation, color);
        }

        void SetOrigin(Vector2 newOrigin)
        {
            m_spriteOrigin = newOrigin;
        }

        virtual void Begin() override
        {
        }

        virtual void Render() override
        {
        }

        virtual void Update() override
        {
        }
    };
} // namespace rpg
