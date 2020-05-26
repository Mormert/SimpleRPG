#include "text_renderer_UI.hpp"

#include <raylib.h>

namespace rpg::components
{

    TextRendererUI::TextRendererUI(int x, int y, const std::string &text, int fontSize, Color color)
        : m_x{x}, m_y{y}, m_text{text}, m_fontSize{fontSize}, m_color{color}
    {
    }

    void TextRendererUI::RenderUI()
    {
        DrawText(m_text.c_str(), m_x, m_y, m_fontSize, m_color);
    }

} // namespace rpg::components