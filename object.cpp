#include "object.hpp"

namespace rpg
{
    // Called in update pass
    void Object::Update()
    {
        for (auto component : m_components)
        {
            component->Update();
        }
    }

    // Called in render pass
    void Object::Render()
    {
        for (auto component : m_components)
        {
            component->Render();
        }
    }

    // Frees all components
    Object::~Object()
    {
        for (auto component : m_components)
        {
            delete component;
        }
    }

} // namespace rpg