#include "object.hpp"

namespace rpg::objects
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

    // Called in render ui pass
    void Object::RenderUI()
    {
        for (auto component : m_components)
        {
            component->RenderUI();
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

    void Object::ObjectInitFromFile(std::ifstream &fileIn) {}

    Object *ObjectFactory::CreateInstance(std::string const &s)
    {
        map_type::iterator it = GetMap()->find(s);
        if (it == GetMap()->end())
        {
            throw std::exception("Corrupted scene!");
            return 0;
        }

        return it->second();
    }

    map_type *ObjectFactory::GetMap()
    {
        if (!map)
        {
            map = new map_type;
        }
        return map;
    }

    map_type *ObjectFactory::map{nullptr};

} // namespace rpg