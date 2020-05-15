#include "object_manager.hpp"

#include <algorithm>

namespace rpg
{

    void ObjectManager::Update()
    {
        for (auto object : m_objects)
        {
            object->Update();
        }
    }

    void ObjectManager::Render()
    {
        for (auto object : m_objects)
        {
            object->Render();
        }
    }

    void ObjectManager::AddObject(Object *object)
    {
        m_objects.push_back(object);
    }

    void ObjectManager::RemoveObject(Object *object)
    {
        m_objects.erase(std::remove(m_objects.begin(), m_objects.end(), object), m_objects.end());
    }

    ObjectManager::~ObjectManager()
    {
        for (auto object : m_objects)
        {
            delete object;
        }
    }

} // namespace rpg