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
            if (object.at(0) == '#')
            {
                // If this line is a comment (starting with #), skip it
                std::getline(fileIn, object);
            }
            else
            {
                try
                {
                    Object *newObject = ObjectFactory::CreateInstance(object);
                    newObject->ObjectInitFromFile(fileIn);
                    objectManager.AddObject(newObject);
                }
                catch (std::exception &e)
                {
                    std::cerr << e.what() << " Exiting!" << std::endl;
                    exit(1);
                }
            }
        }
    }

} // namespace rpg