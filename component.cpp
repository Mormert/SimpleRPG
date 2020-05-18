#include "component.hpp"

#include <iostream>

namespace rpg
{

    void Component::Update(){};
    void Component::Render(){};

    Component::~Component()
    {
        std::cout << "Calling ~IComponent()" << std::endl;
    }
} // namespace rpg