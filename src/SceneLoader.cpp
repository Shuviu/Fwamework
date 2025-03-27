//
// Created by shuviu on 3/19/25.
//

#include "../include/SceneLoader.h"

#include <fstream>
#include <iostream>
#include <vector>

#include "../include/Scene.h"
#include "../include/Asset.h"
#include "../include/AssetRegister.hpp"
using namespace Assets;

namespace Scenes {
    // ---- Methods ---- //

    // Loads the entire Scene provided with pathToFile including Assets
    // Asset constructors and names have to be provided within the assetMap
    std::tuple<std::vector<std::string>, std::vector<Asset> > SceneLoader::LoadSceneFile(const std::string *pathToFile, Assets::AssetRegister &assetRegister) {
        // Open Filestream
        std::ifstream file (*pathToFile);
        std::string line;

        // Skip to the Scene Region
        while (line != "[SCENE]") {
            std::getline(file, line);
        };

        // Load Scene Region
        std::vector<std::string> sceneReg = LoadSceneRegion(&file);
        // Skip lines to the Asset Region
        while (line != "[ASSETS]") {
            std::getline(file, line);
        }
        // Load the Assets from file
        std::vector<Asset> assets = LoadAssets(&file, assetRegister);

        return {sceneReg, assets};
    }

    // Reads and returns the SceneRegion in a provided file.
    std::vector<std::string>SceneLoader::LoadSceneRegion(std::ifstream* filestream) {
        std::string line;
        std::vector<std::string> lines;

        // Read all relevant lines
        while (line != "[ENDSCENE]") {
            std::getline(*filestream, line);
            if (line == "[ENDSCENE]" )
                break;
            // Push onto vector
            lines.push_back(std::move(line));
        }
        return lines;
    }

    // Loads and returns the stored Assets from a provided file.
    std::vector<Asset> SceneLoader::LoadAssets(std::ifstream *filestream, Assets::AssetRegister &assetRegister) {
        std::vector<Asset> assets;
        std::string line;

        // Read all relevant lines
        while (line != "[ENDASSETS]") {
            std::getline(*filestream, line);
            if (line == "[ENDASSETS]" )
                break;
            // Fetch Asset name from line (First field before ;)
            std::string assetName = line.substr(0, line.find(';'));

            // Check if Class is registered
            if (!assetRegister.GetRegistry().contains(assetName)) {
                throw std::runtime_error("Assets not registered");
            }

            // Fetch the AssetConstructor from the assetMap
            auto assetConst = assetRegister.GetRegistry().find(assetName)->second;
            // Push onto vec
            assets.push_back(assetConst(1, 2));
        }
        return assets;
    }
}
