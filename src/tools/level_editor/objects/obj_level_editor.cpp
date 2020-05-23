#include "obj_level_editor.hpp"

#include "comp_object_placer.hpp"

namespace rpg::objects
{
    LevelEditor::LevelEditor() {}

    void LevelEditor::ObjectInitFromFile(std::ifstream &fileIn)
    {
        components::ObjectPlacer *objectPlacer = new components::ObjectPlacer{};
        AddComponent(objectPlacer);
    }

    REGISTER_DEF_TYPE(LevelEditor);

} // namespace rpg::objects