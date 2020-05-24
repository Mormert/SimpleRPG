#include "obj_level_editor.hpp"

#include "comp_level_editor_main.hpp"
#include "comp_object_placer.hpp"
#include "comp_object_selector.hpp"

#include <string>

namespace rpg::objects
{
    LevelEditor::LevelEditor() {}

    void LevelEditor::ObjectInitFromFile(std::ifstream &fileIn)
    {
        int gridSizeX, gridSizeY;
        std::string spriteSheetName;
        fileIn >> spriteSheetName >> gridSizeX >> gridSizeY;

        components::LevelEditorComp *levelEditor = new components::LevelEditorComp{gridSizeX, gridSizeY};
        components::ObjectPlacer *objectPlacer = new components::ObjectPlacer{levelEditor};
        components::ObjectSelector *objectSelector = new components::ObjectSelector{objectPlacer, spriteSheetName};

        AddComponent(levelEditor);
        AddComponent(objectSelector);
        AddComponent(objectPlacer);
    }

    REGISTER_DEF_TYPE(LevelEditor);

} // namespace rpg::objects