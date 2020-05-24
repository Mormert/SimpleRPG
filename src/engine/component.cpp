#include "component.hpp"

#include <iostream>

namespace rpg::components
{

    void Component::Update(){};
    void Component::Render(){};
    void Component::RenderUI(){};

    Component::~Component() {}
} // namespace rpg::components