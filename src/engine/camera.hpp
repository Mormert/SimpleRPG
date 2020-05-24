#ifndef RPG_ENGINE_CAMERA_HPP
#define RPG_ENGINE_CAMERA_HPP

#include <raylib.h>

namespace rpg
{
    class Camera
    {
    private:
        static Camera2D m_camera;
        static Color m_backgroundColor;

    public:
        static void
        SetRotation(float rotation);
        static float GetRotation();

        static void SetZoom(float zoom);
        static float GetZoom();

        static void SetTarget(int x, int y);
        static void SetTarget(float x, float y);

        static void SetOffset(int x, int y);
        static Vector2 GetOffset();

        static Vector2 GetTarget();

        static void SetBackgroundColor(Color color);
        static Color &GetBackgroundColor();

        static Camera2D &GetCameraRef();
    };
} // namespace rpg

#endif // RPG_ENGINE_CAMERA_HPP