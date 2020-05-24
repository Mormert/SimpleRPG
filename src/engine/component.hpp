#ifndef COMPONENT_HPP
#define COMPONENT_HPP

namespace rpg::components
{

    class Component
    {
    public:
        virtual void Update();
        virtual void Render();
        virtual void RenderUI();

        virtual ~Component();
    };
} // namespace rpg

#endif