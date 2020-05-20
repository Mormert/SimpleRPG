#ifndef MY_OBJECT_TEMPLATE_HPP
#define MY_OBJECT_TEMPLATE_HPP

#include "object.hpp"

namespace rpg::objects
{
    class MyObject : public Object
    {
    private:
        REGISTER_DEC_TYPE(MyObject);

    public:
        virtual void ObjectInitFromFile(std::ifstream &fileIn) override;
        MyObject();

        // Add components where it so fits, by AddComponent(new ... {});
    };
} // namespace rpg::objects

#endif // MY_OBJECT_TEMPLATE_HPP