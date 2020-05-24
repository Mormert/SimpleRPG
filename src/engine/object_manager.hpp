#pragma once

#include <vector>

#include "object.hpp"

namespace rpg
{
    class ObjectManager
    {

    private:
        std::vector<objects::Object *> m_objects;

    public:

        void Update();

        void Render();

        void RenderUI();

        void AddObject(objects::Object *object);

        // Also deletes the object by pointer
        void RemoveObject(objects::Object *object);

        ~ObjectManager();

    };
} // namespace rpg
