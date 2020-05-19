#include "camera.hpp"

#include <raylib.h>

namespace rpg
{

    Camera2D Camera::m_camera{0};

    void Camera::SetRotation(float rotation)
    {
        m_camera.rotation = rotation;
    }

    float Camera::GetRotation()
    {
        return m_camera.rotation;
    }

    void Camera::SetZoom(float zoom)
    {
        m_camera.zoom = zoom;
    }

    void Camera::SetTarget(int x, int y)
    {
        m_camera.target = Vector2{static_cast<float>(x), static_cast<float>(y)};
    }

    void Camera::SetTarget(float x, float y)
    {
        m_camera.target = Vector2{x, y};
    }

    Vector2 Camera::GetTarget()
    {
        return m_camera.target;
    }

    Camera2D &Camera::GetCameraRef()
    {
        return m_camera;
    }

} // namespace rpg