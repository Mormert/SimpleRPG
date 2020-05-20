#include "comp_top_down_controller.hpp"

namespace rpg::components
{

    TopDownController::TopDownController(Transform *transformComponent)
        : m_transform{transformComponent} {}

    void TopDownController::MoveUp(int amount)
    {
        m_transform->y -= amount;
    }
    void TopDownController::MoveDown(int amount)
    {
        m_transform->y += amount;
    }
    void TopDownController::MoveLeft(int amount)
    {
        m_transform->x -= amount;
    }
    void TopDownController::MoveRight(int amount)
    {
        m_transform->x += amount;
    }

} // namespace rpg::components