#include "comp_player_controller.hpp"

#include <raylib.h>

namespace rpg::components
{

    PlayerController::PlayerController(TopDownController *topDownController) : m_topDownController{topDownController}, m_moveSpeed{0}
    {
    }

    // Handles input
    void PlayerController::Update()
    {
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        {
            m_topDownController->MoveLeft(m_moveSpeed);
        }

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        {
            m_topDownController->MoveRight(m_moveSpeed);
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
