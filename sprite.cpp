// #include "sprite.hpp"

// namespace rpg
// {

//     // Sprite::Sprite(Object &callingObject) : IComponent::IComponent{callingObject}, m_spriteRectangle{Rectangle{}}, m_spriteSheetTexture{Texture2D{}}
//     // {
//     // }

//     void Sprite::DrawSprite(int x, int y, float rotation = 0.0f, Color color = WHITE)
//     {
//         Rectangle destinationRectangle{static_cast<float>(x), static_cast<float>(y),
//                                        m_spriteRectangle.width, m_spriteRectangle.height};

//         DrawTexturePro(m_spriteSheetTexture, m_spriteRectangle, destinationRectangle,
//                        m_spriteOrigin, rotation, color);
//     }

//     void Sprite::SetOrigin(Vector2 newOrigin)
//     {
//         m_spriteOrigin = newOrigin;
//     }

//     void Sprite::Begin()
//     {
//     }

//     void Sprite::Render()
//     {
//     }

//     void Sprite::Update()
//     {
//     }

// } // namespace rpg