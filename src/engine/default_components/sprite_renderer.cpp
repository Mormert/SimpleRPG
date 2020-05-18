#include "sprite_renderer.hpp"

namespace rpg::components
{

    SpriteRenderer::SpriteRenderer(Transform *transform) : m_transform{*transform} {}

    SpriteRenderer &SpriteRenderer::AddSprite(Sprite *sprite)
    {
        m_sprites.push_back(sprite);
        return *this;
    }

    void SpriteRenderer::Render()
    {
        for (auto sprite : m_sprites)
        {
            sprite->DrawSprite(m_transform.x, m_transform.y, m_transform.rotation);
        }
    }

    SpriteRenderer::~SpriteRenderer()
    {
        for (auto sprite : m_sprites)
        {
            delete sprite;
        }
    }

} // namespace rpg