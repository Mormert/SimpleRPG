#ifndef RPG_TOOLS_LEVEL_EDITOR_HPP
#define RPG_TOOLS_LEVEL_EDITOR_HPP

#include "object.hpp"

namespace rpg::objects
{
    class LevelEditor : public Object
    {
    private:
        REGISTER_DEC_TYPE(LevelEditor);

    public:
        virtual void ObjectInitFromFile(std::ifstream &fileIn) override;
        LevelEditor();
    };
} // namespace rpg::objects

#endif // RPG_TOOLS_LEVEL_EDITOR_HPP