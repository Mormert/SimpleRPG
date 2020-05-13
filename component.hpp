#pragma once

namespace rpg
{
    class IComponent
    {
    public:
        virtual void Begin() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
    };
} // namespace rpg
