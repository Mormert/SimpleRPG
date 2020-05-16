#include "scene_loader.hpp"

#include "testobject.hpp"

#include <string>
#include <iostream>
#include <fstream>

namespace rpg
{

    SceneLoader::SceneLoader(std::string sceneFileName, ObjectManager &objectManager)
    {
        std::ifstream fin(sceneFileName);

        int id;
        while (fin >> id)
        {
            switch (id)
            {
            case 0:
                int x, y, sx, sy, sw, sh;
                std::string path;
                fin >> x >> y >> sx >> sy >> sw >> sh >> path;
                objectManager.AddObject(new TestObject{x, y, sx, sy, sw, sh, path});
                break;
            }
        }
    }

} // namespace rpg