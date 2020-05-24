#ifndef RPG_TOOLS_LEVEL_EDITOR_HPP
#define RPG_TOOLS_LEVEL_EDITOR_HPP

#include "object.hpp"
#include "object_manager.hpp"

namespace rpg::objects
{
    class LevelEditor : public Object
    {
    private:
        REGISTER_DEC_TYPE(LevelEditor);

    public:
        LevelEditor();
        virtual void ObjectInitFromFile(std::ifstream &fileIn) override;
    };
} // namespace rpg::objects

#endif // RPG_TOOLS_LEVEL_EDITOR_HPP