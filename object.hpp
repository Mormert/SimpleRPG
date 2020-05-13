#pragma once

#include <vector>

#include "component.hpp"

namespace rpg
{
    class Object
    {

    private:
        std::vector<IComponent*> m_components;

    public:
        void Update()
        {
            for (auto component : m_components)
            {
                component->Update();
            }
        }

        void Render()
        {
            for (auto component : m_components)
            {
                component->Render();
            }
        }

        void AddComponent(IComponent& component)
        {
            m_components.push_back(&component);
            component.Begin();
        }
    };
} // namespace rpg
