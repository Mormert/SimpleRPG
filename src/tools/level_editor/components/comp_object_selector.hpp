#ifndef TOOLS_COMPONENT_OBJECT_SELECTOR_HPP
#define TOOLS_COMPONENT_OBJECT_SELECTOR_HPP

#include "component.hpp"
#include "comp_object_placer.hpp"

namespace rpg::components
{

    class ObjectSelector : public Component
    {
    private:
        int gridX{16};
        int gridY{16};
        ObjectPlacer *m_objectPlacer;

    public:
        ObjectSelector(ObjectPlacer *objectPlacer);
        virtual void Update() override;
        virtual void RenderUI() override;
    };

} // namespace rpg::components

#endif // TOOLS_COMPONENT_OBJECT_SELECTOR_HPP