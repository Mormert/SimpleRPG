#ifndef GAME_COMPONENT_PLAYER_HPP
#define GAME_COMPONENT_PLAYER_HPP

#include "component.hpp"
#include "comp_top_down_controller.hpp"
#include "sprite.hpp"

namespace rpg::components
{

    class PlayerController : public Component
    {

    private:
        TopDownController *m_topDownController;
        Sprite *m_playerSprite;
        int m_moveSpeed;

    public:
        PlayerController(TopDownController *topDownController, Sprite *playerSprite);

        void SetMoveSpeed(int speed);

        // Handles input
        virtual void Update() override;
    };

} // namespace rpg::components

#endif // GAME_COMPONENT_PLAYER_HPP