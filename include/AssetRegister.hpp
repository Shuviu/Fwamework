//
// Created by shuviu on 3/25/25.
//

#ifndef ASSETREGISTER_HPP
#define ASSETREGISTER_HPP
#include <functional>
#include <map>
#include <string>

#include "Asset.h"

namespace Assets {
    class AssetRegister {
        // AsserRegistry for lookup
        std::map<std::string, std::function<Asset(int x, int y)>> registry_;

    public:
        // Registration for a Asset type
        template<class T>
        void RegisterClass(const std::string& name) {
            registry_[name] = [](int x, int y) {return T(x, y);};
        }

        // Getter for the Asset registry
        std::map<std::string, std::function<Asset(int x, int y)>> GetRegistry() {
            return registry_;
        };
    };
}

#endif //ASSETREGISTER_HPP
