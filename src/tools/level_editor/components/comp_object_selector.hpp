#ifndef TOOLS_COMPONENT_OBJECT_SELECTOR_HPP
#define TOOLS_COMPONENT_OBJECT_SELECTOR_HPP

#include "component.hpp"
#include "comp_object_placer.hpp"

#include <raylib.h>

#include <string>

namespace rpg::components
{

    class ObjectSelector : public Component
    {
    private:
        int selectorWindowX{50};
        int selectorWindowY{50};

        const int_fast8_t &m_gridX; // Reference to grid sizes in LevelEditorComp
        const int_fast8_t &m_gridY;

        ObjectPlacer *m_objectPlacer;
        std::string m_spriteSheetName;
        Texture2D m_spriteSheetTexture;

    public:
        ObjectSelector(ObjectPlacer *objectPlacer, const std::string &spriteSheetName);
        virtual void Update() override;
        virtual void RenderUI() override;
    };

} // namespace rpg::components

#endif // TOOLS_COMPONENT_OBJECT_SELECTOR_HPP