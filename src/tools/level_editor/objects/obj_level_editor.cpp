#include "obj_level_editor.hpp"

#include "comp_level_editor_main.hpp"
#include "comp_object_placer.hpp"
#include "comp_object_selector.hpp"

namespace rpg::objects
{
    LevelEditor::LevelEditor() {}

    void LevelEditor::ObjectInitFromFile(std::ifstream &fileIn)
    {
        components::LevelEditorComp *levelEditor = new components::LevelEditorComp{};
        components::ObjectPlacer *objectPlacer = new components::ObjectPlacer{levelEditor->GetObjectManager()};
        components::ObjectSelector *objectSelector = new components::ObjectSelector{objectPlacer};

        AddComponent(levelEditor);
        AddComponent(objectSelector);
        AddComponent(objectPlacer);
    }

    REGISTER_DEF_TYPE(LevelEditor);

} // namespace rpg::objects