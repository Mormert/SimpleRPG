#ifndef SPRITE_RENDERER_HPP
#define SPRITE_RENDERER_HPP

#include "../component.hpp"
#include "../sprite.hpp"
#include "transform.hpp"

#include <vector>

namespace rpg::components
{
    class SpriteRenderer : public Component
    {

    private:
        std::vector<Sprite *> m_sprites;

        // A SpriteRenderer component requieres a Transform component
        // And it should of course be from the same object
        rpg::components::Transform &m_transform;

    public:
        SpriteRenderer(Transform *transform);

        SpriteRenderer &AddSprite(Sprite *sprite);

        ~SpriteRenderer();

        virtual void Render() override;
    };

} // namespace rpg

#endif // SPRITE_RENDERER_HPP