#ifndef ENGINE_DEFAULT_BOJECT_ERROR_MESSAGE_HPP
#define ENGINE_DEFAULT_BOJECT_ERROR_MESSAGE_HPP

#include "object.hpp"

#include <string>
#include <map>

#include <raylib.h>

// This object can not be instantiated via file, it is only to be used
// to show errors to the user

namespace rpg
{
    class ErrorMessage : public objects::Object
    {
    private:
        std::string m_message;

        ErrorMessage(const std::string &message);

    public:
        static void ThrowMessage(const std::string &message);
    };
} // namespace rpg

#endif // ENGINE_DEFAULT_BOJECT_ERROR_MESSAGE_HPP