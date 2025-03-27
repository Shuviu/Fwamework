//
// Created by shuviu on 3/15/25.
//

#ifndef SCENE_H
#define SCENE_H
#include <functional>
#include <map>
#include <string>
#include <vector>

#include "Asset.h"
#include "AssetRegister.hpp"

namespace Scenes {
    class Scene {
    private:
        std::vector<Assets::Asset> assets_;
        std::vector<std::string> sceneMatrix_;
        bool isUpdated_;
    public:
        Scene();
        explicit Scene(const std::string* pathToFile, Assets::AssetRegister &assetRegister);
        ~Scene();

        [[nodiscard]] std::vector<std::string> GetSceneMatrix() const;
        std::vector<Assets::Asset>* GetAssets();

        void SetSceneMatrix(std::vector<std::string> sceneMatrix);
        void SetAssetsVector(const std::vector<Assets::Asset>& assets_);
        void AddAsset(const Assets::Asset& asset);
        void RemoveAsset(const Assets::Asset& asset);
        void Render();
    };
}



#endif //SCENE_H
