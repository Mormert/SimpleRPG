#include "error_message.hpp"

#include "text_renderer_UI.hpp"
#include "object_manager.hpp"

#include <raylib.h>

// This object can not be instantiated via file, it is only to be used
// to show errors to the user

namespace rpg
{

    void ErrorMessage::ThrowMessage(const std::string &message)
    {
        ObjectManager *mainObjectManager = ObjectManager::GetMainObjectManager();
        ErrorMessage *errorMessage{new ErrorMessage{message}};
        mainObjectManager->AddObject(errorMessage);
    }

    ErrorMessage::ErrorMessage(const std::string &message) : m_message{message}
    {
        components::TextRendererUI *textRendererUI{new components::TextRendererUI{GetScreenWidth() / 2, GetScreenHeight() / 2, message, 24, RED}};
        AddComponent(textRendererUI);
    }

} // namespace rpg