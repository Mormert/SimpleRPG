#include "error_message.hpp"

#include "text_renderer_UI.hpp"
#include "transform.hpp"

#include <raylib.h>

namespace rpg::objects
{

    ErrorMessage::ErrorMessage(const std::string &message) : m_message{message}
    {

        components::TextRendererUI *textRendererUI{new components::TextRendererUI{GetScreenWidth() / 2, GetScreenHeight() / 2, message, 24, RED}};

        AddComponent(textRendererUI);
    }

} // namespace rpg::objects