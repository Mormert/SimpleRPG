#ifndef TOOLS_COMPONENT_LEVEL_EDITOR_MAIN_HPP
#define TOOLS_COMPONENT_LEVEL_EDITOR_MAIN_HPP

#include "component.hpp"
#include "object.hpp"
#include "object_manager.hpp"

namespace rpg::components
{
    class LevelEditorComp : public Component
    {
    private:
        int_fast8_t m_gridX{16};
        int_fast8_t m_gridY{16};
        ObjectManager m_objectManager;

    public:
        LevelEditorComp(int gridSizeX, int gridSizeY);
        ObjectManager *GetObjectManager();
        const int_fast8_t &GetGridSizeX();
        const int_fast8_t &GetGridSizeY();
        virtual void Update() override;
        virtual void Render() override;
    };
} // namespace rpg::components

#endif // TOOLS_COMPONENT_LEVEL_EDITOR_MAIN_HPP