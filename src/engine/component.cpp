#include "component.hpp"

#include <iostream>

namespace rpg::components
{

    void Component::Update(){};
    void Component::Render(){};

    Component::~Component() {}
} // namespace rpg::components