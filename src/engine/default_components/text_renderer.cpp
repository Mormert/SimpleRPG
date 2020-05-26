#include "text_renderer.hpp"

#include <raylib.h>

namespace rpg::components
{

    TextRenderer::TextRenderer(Transform *transform, const std::string &text) : m_transform{*transform}, m_text{text} {}

    void TextRenderer::Render()
    {
        DrawText(m_text.c_str(), m_transform.x, m_transform.y, 24, GRAY);
    }

} // namespace rpg::components