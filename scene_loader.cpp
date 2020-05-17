#include "scene_loader.hpp"

#include "testobject.hpp"

#include <string>
#include <iostream>
#include <fstream>

namespace rpg
{

    SceneLoader::SceneLoader(std::string sceneFileName, ObjectManager &objectManager)
    {
        std::ifstream fileIn(sceneFileName);

        std::string object;
        while (fileIn >> object)
        {
            Object *newObject = ObjectFactory::CreateInstance(object);
            newObject->ObjectInitFromFile(fileIn);
            objectManager.AddObject(newObject);
        }
    }

} // namespace rpg