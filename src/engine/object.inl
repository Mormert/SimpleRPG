#ifndef OBJECT_INL
#define OBJECT_INL

#include <iostream>
#include <typeinfo>

namespace rpg::objects
{
    // Note that Components should be allocated by the "new" keyword
    // They should not consist within local scopes
    template <typename T>
    Object &Object::AddComponent(T *component)
    {
        m_components.push_back(component);

        return *this;
    }

    template <typename T>
    T *Object::GetComponent()
    {
        for (auto component : m_components)
        {
            if (typeid(T) == typeid(*component))
            {
                return static_cast<T *>(component);
            }
        }

        throw std::exception("Could not find component");
        std::cerr << "ERROR: COMPONENT " << typeid(T).name()
                  << " NOT FOUND" << std::endl;
        return nullptr;
    }

} // namespace rpg::objects

#endif // OBJECT_INL