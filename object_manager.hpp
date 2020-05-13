#pragma once

#include <vector>

#include "object.hpp"

namespace rpg
{
    class ObjectManager
    {

    private:
        std::vector<Object> m_objectList;
    };
} // namespace rpg
