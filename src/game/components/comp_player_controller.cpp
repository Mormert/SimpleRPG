#include "comp_player_controller.hpp"

#include <raylib.h>

#include "spritesheet.hpp"

namespace rpg::components
{

    PlayerController::PlayerController(TopDownController *topDownController, Sprite *playerSprite)
        : m_topDownController{topDownController},
          m_playerSprite{playerSprite},
          m_moveSpeed{0}
    {
    }

    // Handles input
    void PlayerController::Update()
    {
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        {
            m_topDownController->MoveLeft(m_moveSpeed);
            m_playerSprite->SetFlipVertical(true);
        }

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        {
            m_topDownController->MoveRight(m_moveSpeed);
            m_playerSprite->SetFlipVertical(false);
        }

        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        {
            m_topDownController->MoveUp(m_moveSpeed);
        }

        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        {
            m_topDownController->MoveDown(m_moveSpeed);
        }
    }

    void PlayerController::SetMoveSpeed(int speed)
    {
        m_moveSpeed = speed;
    }

} // namespace rpg::components
