
#include "comp_level_editor_main.hpp"

namespace rpg::components
{

    ObjectManager *LevelEditorComp::GetObjectManager()
    {
        return &m_objectManager;
    }

    void LevelEditorComp::Update()
    {
        m_objectManager.Update();
    }

    void LevelEditorComp::Render()
    {
        m_objectManager.Render();
    }

} // namespace rpg::components
