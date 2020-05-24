#ifndef TOOLS_COMPONENT_OBJECT_PLACER_HPP
#define TOOLS_COMPONENT_OBJECT_PLACER_HPP

#include "component.hpp"
#include "object.hpp"
#include "object_manager.hpp"

namespace rpg::components
{

    class ObjectPlacer : public Component
    {
    private:
        int gridX{16};
        int gridY{16};
        ObjectManager *m_objectManager;
        objects::Object *m_placeableObject; // Needs to be allocated elsewhere

    public:
        ObjectPlacer(ObjectManager* objectManager);
        virtual void Update() override;
        void QueueObject(objects::Object *object);
        void DequeueObject();
    };

} // namespace rpg::components

#endif // TOOLS_COMPONENT_OBJECT_PLACER_HPP