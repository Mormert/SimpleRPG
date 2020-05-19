#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "component.hpp"

namespace rpg::components
{

    class Transform : public Component
    {
    public:
        float scale;
        float rotation;
        int x;
        int y;

        Transform();

        Transform(int x, int y, float scale = 1.0f, float rotation = 0.0f);
    };

} // namespace rpg

#endif