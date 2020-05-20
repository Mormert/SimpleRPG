#ifndef GAME_COMPONENT_TOP_DOWN_CONTROLLER_HPP
#define GAME_COMPONENT_TOP_DOWN_CONTROLLER_HPP

#include "component.hpp"
#include "transform.hpp"

namespace rpg::components
{

    class TopDownController : public Component
    {

    private:
        Transform *m_transform;

    public:
        TopDownController(Transform *transformComponent);

        void MoveUp(int amount);
        void MoveDown(int amount);
        void MoveLeft(int amount);
        void MoveRight(int amount);
    };

} // namespace rpg::components

#endif // GAME_COMPONENT_TOP_DOWN_CONTROLLER_HPP