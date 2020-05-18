#ifndef SCENE_LOADER_HPP
#define SCENE_LOADER_HPP

#include "object_manager.hpp"

#include <string>

namespace rpg
{
    class SceneLoader
    {
    public:
        // Loads a scene from a file (name.scene), and puts the objects in the objectManager
        SceneLoader(std::string sceneFileName, ObjectManager &objectManager);
    };

} // namespace rpg

#endif // SCENE_LOADER_HPP