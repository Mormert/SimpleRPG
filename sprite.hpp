#pragma once

#include "spritesheet.hpp"
#include "component.hpp"

namespace rpg
{
    class Sprite
    {
    private:
        const Rectangle m_spriteRectangle;     // The bounds of this sprite on
        const Texture2D &m_spriteSheetTexture; // the spritesheet texture

        Vector2 m_spriteOrigin;

    public:

        // A sprite is created as a small piece from a bigger spritesheet
        // x,x              : the top left corner of the subsprite
        // width, height    : the dimensions of the subsprite
        // origin           : the center part of the subsprite
        Sprite(Spritesheet &spriteSheet, float x, float y,
               float width, float heigth, Vector2 origin = {0.0f, 0.0f});

        void DrawSprite(int x, int y, float rotation = 0.0f, Color color = WHITE);

        void SetOrigin(Vector2 newOrigin);

        ~Sprite();

    };
} // namespace rpg
