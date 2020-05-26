#include "object_manager.hpp"

#include <algorithm>

namespace rpg
{

    ObjectManager *ObjectManager::m_mainObjectManager{nullptr};

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

    void ObjectManager::RenderUI()
    {
        for (auto object : m_objects)
        {
            object->RenderUI();
        }
    }

    void ObjectManager::AddObject(objects::Object *object)
    {
        m_objects.push_back(object);
    }

    void ObjectManager::RemoveObject(objects::Object *object)
    {
        m_objects.erase(std::remove(m_objects.begin(), m_objects.end(), object), m_objects.end());
        delete object;
    }

    ObjectManager *ObjectManager::GetMainObjectManager()
    {
        return m_mainObjectManager;
    }

    void ObjectManager::SetMainObjectManager(ObjectManager *objectManager)
    {
        m_mainObjectManager = objectManager;
    }

    ObjectManager::~ObjectManager()
    {
        for (auto object : m_objects)
        {
            delete object;
        }
    }

} // namespace rpg