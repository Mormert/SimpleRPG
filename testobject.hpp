#ifndef TESTOBJECT_HPP
#define TESTOBJECT_HPP

#include "object.hpp"
#include "components_list"

namespace rpg
{
    class TestObject : public Object
    {
    public:
        TestObject(int x, int y, int spriteX, int spriteY, int spriteWidth, int spriteHeight, std::string texturePath);
        TestObject();

    private:
        REGISTER_DEC_TYPE(TestObject);
    };


} // namespace rpg

#endif // TESTOBJECT_HPP