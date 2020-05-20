#ifndef GAME_COMPONENT_CAM_TRANSFORM_HPP
#define GAME_COMPONENT_CAM_TRANSFORM_HPP

#include "component.hpp"
#include "camera.hpp"
#include "transform.hpp"

namespace rpg::components
{

    class CamTransformController : public Component
    {

    private:
        Transform *m_targetTransform;

    public:
        CamTransformController(Transform *target, float zoom = 1.0f);
        virtual void Update() override;
    };

} // namespace rpg::components

#endif // GAME_COMPONENT_CAM_TRANSFORM_HPP