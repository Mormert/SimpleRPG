#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "component.hpp"

#include <vector>

namespace rpg
{
    // Base class for all objects
    class Object
    {
    private:
        std::vector<Component *> m_components;

    public:
        // Called in update pass
        void Update();

        // Called in render pass
        void Render();

        // Deletes all components on destructor
        virtual ~Object();

        // Example: rpg::Object myObject;
        // myObject.AddComponent(new rpg::TestComponent{});
        // Returns Object&, so the function is chainable
        template <typename T>
        Object &AddComponent(T *component);

        // Example: rpg::TestComponent *myComponent =
        // myObject.GetComponent<rpg::TestComponent>();
        // Dont forget to check for nulltpr if the object
        // does not have any component of the type T
        template <typename T>
        T *GetComponent();
    };
} // namespace rpg

#include "object.inl"

#endif