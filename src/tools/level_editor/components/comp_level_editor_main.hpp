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
        ObjectManager m_objectManager;

    public:
        ObjectManager *GetObjectManager();
        virtual void Update() override;
        virtual void Render() override;

    };
} // namespace rpg::components

#endif // TOOLS_COMPONENT_LEVEL_EDITOR_MAIN_HPP