#ifndef TESTOBJECT_HPP
#define TESTOBJECT_HPP

#include "object.hpp"
#include "components_list"

namespace rpg
{
    class TestObject : public Object
    {
    public:
        TestObject(int x, int y);
    };

} // namespace rpg

#endif // TESTOBJECT_HPP