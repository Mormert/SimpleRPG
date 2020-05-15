#ifndef COMPONENT_HPP
#define COMPONENT_HPP

namespace rpg
{

    class Component
    {
    public:
        //virtual void Begin();
        virtual void Update();
        virtual void Render();

        virtual ~Component();
    };
} // namespace rpg

#endif