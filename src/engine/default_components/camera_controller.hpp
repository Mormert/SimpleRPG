#ifndef RPG_ENGINE_CAMERA_CONTROLLER_HPP
#define RPG_ENGINE_CAMERA_CONTROLLER_HPP

#include "component.hpp"

namespace rpg::components
{

    class CameraController : public Component
    {
    private:
        int xPosition, yPosition;
        float rotation, zoom;

    public:
        void SetPosition(int x, int y);
        void SetRotation(float rotation);

        void Move(int x, int y);
        void Rotate(float rotation);
    };

} // namespace rpg::components

#endif // RPG_ENGINE_CAMERA_CONTROLLER_HPP