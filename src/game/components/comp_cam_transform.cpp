#include "comp_cam_transform.hpp"


#include <raylib.h>

#include <algorithm>

namespace rpg::components
{

    CamTransformController::CamTransformController(Transform *target, float zoom)
    {
        m_targetTransform = target;
        Camera::SetZoom(zoom);
        Camera::SetOffset(GetScreenWidth() / 2, GetScreenHeight() / 2);
        Camera::SetTarget(target->x, target->y);
    }

    void CamTransformController::Update()
    {
        if (IsWindowResized())
        {
            Camera::SetOffset(GetScreenWidth() / 2, GetScreenHeight() / 2);
        }

        float zoomChange = GetMouseWheelMove() * 0.05f;

        if (zoomChange)
        {
            float currentZoom = Camera::GetZoom();
            float newZoom = currentZoom + zoomChange;
            newZoom = std::clamp(newZoom, 1.0f, 5.0f);

            Camera::SetZoom(newZoom);
        }

        Camera::SetTarget(m_targetTransform->x, m_targetTransform->y);
    }
} // namespace rpg::components
