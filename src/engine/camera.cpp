#include "camera.hpp"

#include <raylib.h>

namespace rpg
{

    Camera2D Camera::m_camera{0};

    int Camera::m_offsetX{0};
    int Camera::m_offsetY{0};
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
        m_camera.target = Vector2{static_cast<float>(x + m_offsetX), static_cast<float>(y + m_offsetY)};
    }

    void Camera::SetTarget(float x, float y)
    {
        m_camera.target = Vector2{x + m_offsetX, y + m_offsetY};
    }

    void Camera::SetOffset(int x, int y)
    {
        m_offsetX = -x;
        m_offsetY = -y;
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