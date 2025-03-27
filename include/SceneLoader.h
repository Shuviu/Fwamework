//
// Created by shuviu on 3/19/25.
//

#ifndef SCNELOADER_H
#define SCNELOADER_H
#include <functional>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "Asset.h"
#include "AssetRegister.hpp"


namespace Scenes {
    class SceneLoader {
    private:
        static std::vector<std::string> LoadSceneRegion(std::ifstream* filestream);
        static std::vector<Assets::Asset> LoadAssets(std::ifstream *filestream, Assets::AssetRegister &assetRegister);
    public:
        static std::tuple<std::vector<std::string>, std::vector<Assets::Asset>> LoadSceneFile(
            const std::string *pathToFile, Assets::AssetRegister &assetRegister);
    };
}



#endif //SCNELOADER_H
