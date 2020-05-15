#ifndef TESTCOMPONENT_HPP
#define TESTCOMPONENT_HPP

#include "component.hpp"

#include <iostream>

namespace rpg
{

    class TestComponent : public Component
    {

    private:
        int myInt{0};

    public:
        // virtual void Begin() override
        // {
        //     std::cout << "Calling Begin()" << std::endl;
        // }
        virtual void Update() override
        {
            std::cout << "Calling Update()" << std::endl;
        }
        virtual void Render() override
        {
            std::cout << "Calling Render()" << std::endl;
        }

        int GetTestInt()
        {
            std::cout << "Calling GetTestInt()" << std::endl;
            return myInt;
        }
    };

} // namespace rpg

#endif // TESTCOMPONENT_HPP