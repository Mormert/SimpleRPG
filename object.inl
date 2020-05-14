#ifndef OBJECT_INL
#define OBJECT_INL

#include <iostream>
#include <typeinfo>

namespace rpg
{
    template <typename T>
    Object &Object::AddComponent(T *component)
    {
        m_components.push_back(component);
        std::cout << "Adding component" << '\n';

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

        std::cerr << "ERROR: COMPONENT " << typeid(T).name()
                  << " NOT FOUND" << std::endl;
        return nullptr;
    }

} // namespace rpg

#endif // OBJECT_INL