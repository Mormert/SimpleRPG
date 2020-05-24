#include "comp_object_selector.hpp"

#include "testobject.hpp"
#include "spritesheet.hpp"

#include <raylib.h>

namespace rpg::components
{

    ObjectSelector::ObjectSelector(ObjectPlacer *objectPlacer)
        : m_objectPlacer{objectPlacer}
    {
        m_objectPlacer->QueueObject(new rpg::objects::TestObject{0, 0, 64, 128, 32, 32, "assets/tilesetA.png"});
    }

    void ObjectSelector::Update()
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            int mx = GetMouseX();
            int my = GetMouseY();
            if ((mx >= 25 && mx <= (25 + 256)) && (my >= 25 && my <= (25 + 256)))
            {
                std::cout << "clicked within bounds\n";
                mx -= 25;
                my -= 25;
                mx /= 16;
                my /= 16;
                m_objectPlacer->QueueObject(new rpg::objects::TestObject{0, 0, mx * 16, my * 16, 16, 16, "assets/tilesetA.png"});
                //m_objectPlacer->QueueObject(new rpg::objects::TestObject{0, 0, })
            }
        }
    }

    void ObjectSelector::RenderUI()
    {
        DrawRectangle(20, 20, 256 + 10, 256 + 10, GRAY);
        DrawTexture(objects::SpriteSheet::GetTexture("assets/tilesetA.png"), 25, 25, WHITE);
    }

} // namespace rpg::components