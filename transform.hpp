#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "component.hpp"

namespace rpg
{

    class Transform : public Component
    {
    public:
        float scale;
        float rotation;
        int x;
        int y;
    };

} // namespace rpg

#endif