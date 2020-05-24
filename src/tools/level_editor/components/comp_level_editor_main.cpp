
#include "comp_level_editor_main.hpp"

#include <raylib.h>

namespace rpg::components
{

    LevelEditorComp::LevelEditorComp(int gridSizeX, int gridSizeY) : m_gridX{static_cast<int_fast8_t>(gridSizeX)},
                                                                     m_gridY{static_cast<int_fast8_t>(gridSizeY)}
    {
        SetWindowTitle("Simple & Open RPG - Level Editor");
    }

    ObjectManager *LevelEditorComp::GetObjectManager()
    {
        return &m_objectManager;
    }

    const int_fast8_t &LevelEditorComp::GetGridSizeX()
    {
        return m_gridX;
    }

    const int_fast8_t &LevelEditorComp::GetGridSizeY()
    {
        return m_gridY;
    }

    void LevelEditorComp::Update()
    {
        m_objectManager.Update();
    }

    void LevelEditorComp::Render()
    {
        // Render grid
        for (int i = -10; i <= 10; i++)
        {
            DrawLine(-10 * m_gridX, i * m_gridY, 10 * m_gridX, i * m_gridY, BLACK);
            DrawLine(i * m_gridX, -10 * m_gridY, i * m_gridX, 10 * m_gridY, BLACK);
        }
        m_objectManager.Render();
    }

} // namespace rpg::components
