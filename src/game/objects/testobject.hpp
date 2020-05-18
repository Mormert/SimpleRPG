#ifndef TESTOBJECT_HPP
#define TESTOBJECT_HPP

#include "object.hpp"

namespace rpg::objects
{
    class TestObject : public Object
    {
    private:
        void AddComponents(int x, int y, int spriteX, int spriteY, int spriteWidth, int spriteHeight, std::string texturePath);

    public:
        TestObject();
        TestObject(int x, int y, int spriteX, int spriteY, int spriteWidth, int spriteHeight, std::string texturePath);
        virtual void ObjectInitFromFile(std::ifstream &fileIn) override;

    private:
        REGISTER_DEC_TYPE(TestObject);
    };

} // namespace rpg

#endif // TESTOBJECT_HPP