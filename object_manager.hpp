#pragma once

#include <vector>

#include "object.hpp"

namespace rpg
{
    class ObjectManager
    {

    private:
        std::vector<Object *> m_objects;

    public:

        void Update();

        void Render();

        void AddObject(Object *object);

        void RemoveObject(Object *object);

        ~ObjectManager();

    };
} // namespace rpg
