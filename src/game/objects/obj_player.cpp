#include "obj_player.hpp"

#include "transform.hpp"
#include "sprite_renderer.hpp"
#include "sprite.hpp"
#include "comp_player_controller.hpp"
#include "comp_cam_transform.hpp"

namespace rpg::objects
{
    Player::Player() {}

    void Player::ObjectInitFromFile(std::ifstream &fileIn)
    {

        std::string texturePath;
        int x, y, spriteX, spriteY, spriteWidth, spriteHeight, moveSpeed;
        fileIn >> x >> y >> spriteX >> spriteY >> spriteWidth >> spriteHeight >> texturePath >> moveSpeed;

        components::Transform *transform = new components::Transform(x, y);
        components::SpriteRenderer *spriteRenderer = new components::SpriteRenderer(transform);
        components::CamTransformController *camController = new components::CamTransformController(transform, 5.0f);
        components::TopDownController *topDownController = new components::TopDownController(transform);
        components::PlayerController *player = new components::PlayerController(topDownController);
        player->SetMoveSpeed(moveSpeed);

        Sprite *sprite = new rpg::Sprite{
            rpg::objects::SpriteSheet::GetTexture(texturePath.c_str()), spriteX, spriteY, spriteWidth, spriteHeight};
        sprite->SetOrigin(Vector2{spriteWidth / 2.0f, spriteHeight / 2.0f});
        spriteRenderer->AddSprite(sprite);

        // Note that the order of which the componets are added have an
        // impact on the which order of the components update method is called
        AddComponent(transform);
        AddComponent(spriteRenderer);
        AddComponent(camController);
        AddComponent(topDownController);
        AddComponent(player);
    }

    REGISTER_DEF_TYPE(Player);

} // namespace rpg::objects