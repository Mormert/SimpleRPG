#include "obj_player.hpp"

#include "transform.hpp"
#include "sprite_renderer.hpp"
#include "sprite.hpp"
#include "comp_player_controller.hpp"

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
        components::TopDownController *topDownController = new components::TopDownController(transform);
        components::PlayerController *player = new components::PlayerController(topDownController);
        player->SetMoveSpeed(moveSpeed);

        Sprite *sprite = new rpg::Sprite{
            rpg::objects::SpriteSheet::GetTexture(texturePath.c_str()), spriteX, spriteY, spriteWidth, spriteHeight};
        spriteRenderer->AddSprite(sprite);

        AddComponent(transform);
        AddComponent(spriteRenderer);
        AddComponent(topDownController);
        AddComponent(player);
    }

    REGISTER_DEF_TYPE(Player);

} // namespace rpg::objects