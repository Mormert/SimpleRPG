#ifndef TOOLS_COMPONENT_OBJECT_PLACER_HPP
#define TOOLS_COMPONENT_OBJECT_PLACER_HPP

#include "component.hpp"
#include "object_manager.hpp"

namespace rpg::components
{

    class ObjectPlacer : public Component
    {
    private:
        ObjectManager m_objectManager;
    public:
        ObjectPlacer();
        virtual void Update() override;
        virtual void Render() override;
    };

} // namespace rpg::components

#endif // TOOLS_COMPONENT_OBJECT_PLACER_HPP