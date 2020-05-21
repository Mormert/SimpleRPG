#pragma once

#include "spritesheet.hpp"
#include "component.hpp"

namespace rpg
{
    class Sprite
    {
    private:
        Rectangle m_spriteRectangle;           // The bounds of this sprite on
        const Texture2D &m_spriteSheetTexture; // the spritesheet texture

        int_fast8_t m_verticalFlip{1};
        int_fast8_t m_horizontalFlip{1};

        Vector2 m_spriteOrigin;

    public:
        // A sprite is created as a small piece from a bigger spritesheet
        // x,x              : the top left corner of the subsprite
        // width, height    : the dimensions of the subsprite
        // origin           : the center part of the subsprite
        Sprite(const Texture2D &texture, int x, int y,
               int width, int heigth, Vector2 origin = {0.0f, 0.0f});

        // Renders the sprite for 1 frame
        void DrawSprite(int x, int y, float rotation = 0.0f, Color color = WHITE);

        void SetFlipVertical(bool setFlip);
        void SetFlipHorizontal(bool setFlip);

        bool IsFlippedVertical();
        bool IsFlippedHorizontal();

        void SetOrigin(Vector2 newOrigin);

        ~Sprite();
    };
} // namespace rpg
