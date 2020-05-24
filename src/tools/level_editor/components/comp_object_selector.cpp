#include "comp_object_selector.hpp"

#include "testobject.hpp"
#include "spritesheet.hpp"

#include <raylib.h>

namespace rpg::components
{

    ObjectSelector::ObjectSelector(ObjectPlacer *objectPlacer, const std::string &spriteSheetName)
        : m_objectPlacer{objectPlacer},
          m_spriteSheetName{spriteSheetName},
          m_spriteSheetTexture{objects::SpriteSheet::GetTexture(spriteSheetName)},
          m_gridX{objectPlacer->GetGridSizeX()},
          m_gridY{objectPlacer->GetGridSizeY()}
    {
    }

    void ObjectSelector::Update()
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            int mx = GetMouseX();
            int my = GetMouseY();
            if ((mx >= selectorWindowX && mx <= (selectorWindowX + m_spriteSheetTexture.width)) &&
                (my >= selectorWindowY && my <= (selectorWindowY + m_spriteSheetTexture.height)))
            {
                mx -= selectorWindowX;
                my -= selectorWindowY;
                mx /= m_gridX;
                my /= m_gridY;
                m_objectPlacer->QueueObject(new rpg::objects::TestObject{0, 0, mx * m_gridX, my * m_gridY, m_gridX, m_gridY, m_spriteSheetName});
                // Note that we place the object at (0,0), but this is only a temporary position, later moved by the object placer.
            }
        }
    }

    void ObjectSelector::RenderUI()
    {
        DrawRectangle(selectorWindowX - 5, selectorWindowY - 5, m_spriteSheetTexture.width + 10, m_spriteSheetTexture.height + 10, GRAY);
        DrawRectangleLines(selectorWindowX - 5, selectorWindowY - 5, m_spriteSheetTexture.width + 10, m_spriteSheetTexture.height + 10, BLACK);

        DrawTexture(m_spriteSheetTexture, selectorWindowX, selectorWindowY, WHITE);

        for (int i = 0; i <= m_spriteSheetTexture.width / m_gridY; i++)
        {
            DrawLine(selectorWindowX, i * m_gridY + selectorWindowY, m_spriteSheetTexture.height + selectorWindowX, i * m_gridY + selectorWindowY, BLACK);
        }
        for (int i = 0; i <= m_spriteSheetTexture.height / m_gridX; i++)
        {
            DrawLine(selectorWindowX + i * m_gridX, selectorWindowY, selectorWindowX + i * m_gridX, selectorWindowY + m_spriteSheetTexture.width, BLACK);
        }
    }
} // namespace rpg::components