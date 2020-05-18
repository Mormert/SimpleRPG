#include "transform.hpp"

namespace rpg::components
{

    Transform::Transform()
        : x{0}, y{0}, scale{1.0f}, rotation{0.0f}
    {
    }

    Transform::Transform(int x, int y, float scale, float rotation)
        : x{x}, y{y}, scale{scale}, rotation{rotation}
    {
    }

} // namespace rpg