#ifndef DEFAULT_COMPONENT_TEXT_RENDERER_HPP
#define DEFAULT_COMPONENT_TEXT_RENDERER_HPP

#include "component.hpp"
#include "transform.hpp"

#include <string>

namespace rpg::components
{
    class TextRenderer : public Component
    {

    private:
        std::string m_text;

        rpg::components::Transform &m_transform;

    public:
        TextRenderer(Transform *transform, const std::string &text);

        virtual void Render() override;
    };

} // namespace rpg::components

#endif // DEFAULT_COMPONENT_TEXT_RENDERER_HPP