#pragma once

#include <vector>

#include "object.hpp"

namespace rpg
{
    class ObjectManager
    {

    private:
        std::vector<objects::Object *> m_objects;

        static ObjectManager *m_mainObjectManager;

    public:
        void Update();

        void Render();

        void RenderUI();

        void AddObject(objects::Object *object);

        // Also deletes the object by pointer
        void RemoveObject(objects::Object *object);

        static ObjectManager *GetMainObjectManager();

        // Be very careful using this method, as it is only intended to be
        // used by the core engine to set the main object manager. There can,
        // however, be more than one object manager. (See level editor tool)
        static void SetMainObjectManager(ObjectManager *objectManager);

        ~ObjectManager();
    };
} // namespace rpg
