#pragma once

#include <raylib.h>

#include "spritesheet.hpp"
namespace rpg
{
    class Sprite
    {
    private:
        Rectangle m_spriteRectangle;
        Spritesheet &m_spriteSheet;

    public:
        Sprite(Spritesheet spriteSheet, float x, float y, float width, float heigth) : m_spriteSheet{spriteSheet}, m_spriteRectangle{x, y, width, heigth}
        {
        }


        virtual void DrawSprite(float x, float y)
        {
            //DrawTextureRec(m_spriteSheet.GetTexture(), m_spriteRectangle, Vector2{x, y}, WHITE);
            DrawTextureV(m_spriteSheet.spriteSheet2DTexture, Vector2{100,100}, WHITE);
        }
    };
} // namespace rpg
