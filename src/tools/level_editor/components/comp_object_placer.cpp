#include "comp_object_placer.hpp"
#include "object.hpp"
#include "testobject.hpp"

#include "utils.hpp"

#include <raylib.h>

namespace rpg::components
{
    void ObjectPlacer::Update()
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            int x, y;
            x = utils::GetMouseWorldSpaceX();
            y = utils::GetMouseWorldSpaceY();

            rpg::objects::TestObject *myTestObejct{new rpg::objects::TestObject{x, y, 64, 128, 16, 16, "assets/tilesetA.png"}};
            m_objectManager.AddObject(myTestObejct);
        }

        m_objectManager.Update();
    }

    void ObjectPlacer::Render()
    {
        m_objectManager.Render();
    }

    ObjectPlacer::ObjectPlacer() {}
} // namespace rpg::components