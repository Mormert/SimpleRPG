// #pragma once

// #include <raylib.h>

// #include "spritesheet.hpp"
// #include "component.hpp"
// #include "object.hpp"

// namespace rpg
// {
//     class Sprite : public IComponent
//     {
//     private:
//         const Rectangle m_spriteRectangle;     // The bounds of this sprite on
//         const Texture2D &m_spriteSheetTexture; // the spritesheet texture

//         Vector2 m_spriteOrigin;

//     public:
//         // Sprite(Spritesheet &spriteSheet, float x, float y,
//         //        float width, float heigth, Vector2 origin = {0.0f, 0.0f}) : IComponent::IComponent(),
//         //                                                                    m_spriteRectangle{x, y, width, heigth},
//         //                                                                    m_spriteSheetTexture{spriteSheet.GetTexture()},
//         //                                                                    m_spriteOrigin{origin}
//         // {
//         // }

//         //Sprite(Object &callingObject);

//         void DrawSprite(int x, int y, float rotation = 0.0f, Color color = WHITE);

//         void SetOrigin(Vector2 newOrigin);

//         virtual void Begin();

//         virtual void Render();

//         virtual void Update();
//     };
// } // namespace rpg
