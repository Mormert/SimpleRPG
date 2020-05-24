#include "comp_object_placer.hpp"
#include "object.hpp"
#include "testobject.hpp"
#include "transform.hpp"
#include "utils.hpp"

#include "comp_level_editor_main.hpp"

#include <raylib.h>

namespace rpg::components
{

    ObjectPlacer::ObjectPlacer(LevelEditorComp *levelEditor)
        : m_objectManager{levelEditor->GetObjectManager()},
          m_gridX{levelEditor->GetGridSizeX()},
          m_gridY{levelEditor->GetGridSizeY()} {}

    void ObjectPlacer::Update()
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && m_placeableObject)
        {
            int x, y;
            x = utils::GetMouseWorldSpaceX();
            y = utils::GetMouseWorldSpaceY();

            try
            {
                rpg::components::Transform *transform{m_placeableObject->GetComponent<rpg::components::Transform>()};
                x /= m_gridX;
                y /= m_gridY;
                transform->x = x * m_gridX;
                transform->y = y * m_gridY;

                m_objectManager->AddObject(m_placeableObject);
                m_placeableObject = nullptr;
            }
            catch (std::exception &e)
            {
                std::cerr << e.what() << "\n";
                exit(1);
            }
        }
    }

    void ObjectPlacer::QueueObject(objects::Object *object)
    {
        if (!m_placeableObject)
        {
            delete m_placeableObject;
        }
        m_placeableObject = object;
    }

    void ObjectPlacer::DequeueObject()
    {
        if (!m_placeableObject)
        {
            delete m_placeableObject;
        }
    }

    const int_fast8_t &ObjectPlacer::GetGridSizeX()
    {
        return m_gridX;
    }

    const int_fast8_t &ObjectPlacer::GetGridSizeY()
    {
        return m_gridY;
    }

} // namespace rpg::components