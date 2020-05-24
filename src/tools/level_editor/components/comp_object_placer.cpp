#include "comp_object_placer.hpp"
#include "object.hpp"
#include "testobject.hpp"
#include "transform.hpp"
#include "utils.hpp"

#include <raylib.h>

namespace rpg::components
{

    ObjectPlacer::ObjectPlacer(ObjectManager *objectManager) : m_objectManager{objectManager} {}

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
                x /= 16;
                y /= 16;
                transform->x = x * 16;
                transform->y = y * 16;

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

} // namespace rpg::components