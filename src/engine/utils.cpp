#include "utils.hpp"

#include "camera.hpp"

#include <raylib.h>

namespace rpg::utils
{

    // TODO : Fix this working with zoom properly
    int GetMouseWorldSpaceX()
    {

        int ScreenSpace = GetMouseX();
        int WorldSpace = static_cast<int>(ScreenSpace / Camera::GetZoom() - Camera::GetOffset().x / Camera::GetZoom() + Camera::GetTarget().x / Camera::GetZoom());

        return WorldSpace;
    }

    int GetMouseWorldSpaceY()
    {

        int ScreenSpace = GetMouseY();
        int WorldSpace = static_cast<int>(ScreenSpace / Camera::GetZoom() - Camera::GetOffset().y / Camera::GetZoom() + Camera::GetTarget().y / Camera::GetZoom());

        return WorldSpace;
    }

} // namespace rpg::utils