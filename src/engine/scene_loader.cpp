#include "scene_loader.hpp"

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
                    // Create a new object based on the name of the object string
                    objects::Object *newObject = objects::ObjectFactory::CreateInstance(object);

                    // Passes the file stream to the new object so that the object
                    // can initialize it's values properly, according to the .scene file
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