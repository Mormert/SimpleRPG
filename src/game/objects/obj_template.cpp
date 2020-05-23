#include "obj_template.hpp"

// Don't forget to add me in CMakeLists.txt!

namespace rpg::objects
{
    MyObject::MyObject() {}

    void MyObject::ObjectInitFromFile(std::ifstream &fileIn)
    {
        // Use fileIn to load the variables from file
        // int x, y
        // fileIn >> x >> y;
    }

    // Add components where it so fits, by AddComponent(new ... {});

    REGISTER_DEF_TYPE(MyObject);

} // namespace rpg::objects