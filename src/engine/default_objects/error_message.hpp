#ifndef ENGINE_DEFAULT_BOJECT_ERROR_MESSAGE_HPP
#define ENGINE_DEFAULT_BOJECT_ERROR_MESSAGE_HPP

#include "object.hpp"

#include <string>
#include <map>

#include <raylib.h>

namespace rpg::objects
{
    class ErrorMessage : public Object
    {
    private:
        std::string m_message;

    public:
        ErrorMessage(const std::string &message);
        
    };
} // namespace rpg::objects

#endif // ENGINE_DEFAULT_BOJECT_ERROR_MESSAGE_HPP