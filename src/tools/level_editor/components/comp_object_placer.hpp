#ifndef TOOLS_COMPONENT_OBJECT_PLACER_HPP
#define TOOLS_COMPONENT_OBJECT_PLACER_HPP

#include "component.hpp"
#include "object.hpp"
#include "object_manager.hpp"

#include "comp_level_editor_main.hpp"

namespace rpg::components
{

    class ObjectPlacer : public Component
    {
    private:
        const int_fast8_t &m_gridX;
        const int_fast8_t &m_gridY;
        ObjectManager *m_objectManager;
        objects::Object *m_placeableObject{nullptr}; // Gets set when object is "queued"

    public:
        ObjectPlacer(LevelEditorComp *levelEditor);
        virtual void Update() override;

        const int_fast8_t &GetGridSizeX();
        const int_fast8_t &GetGridSizeY();

        void QueueObject(objects::Object *object);
        void DequeueObject();
    };

} // namespace rpg::components

#endif // TOOLS_COMPONENT_OBJECT_PLACER_HPP