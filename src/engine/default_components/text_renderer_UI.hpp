#ifndef DEFAULT_COMPONENT_TEXT_RENDERER_UI_HPP
#define DEFAULT_COMPONENT_TEXT_RENDERER_UI_HPP

#include "component.hpp"

#include <raylib.h>

#include <string>

namespace rpg::components
{
    class TextRendererUI : public Component
    {

    private:
        std::string m_text;

        int m_x;
        int m_y;
        int m_fontSize;
        Color m_color;

    public:
        TextRendererUI(int x, int y, const std::string &text, int fontSize = 24, Color color = GRAY);

        virtual void RenderUI() override;
    };

} // namespace rpg::components

#endif // DEFAULT_COMPONENT_TEXT_RENDERER_UI_HPP