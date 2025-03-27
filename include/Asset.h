//
// Created by shuviu on 3/18/25.
//

#ifndef ASSET_H
#define ASSET_H
#include <string>
#include <vector>

namespace Assets{

class Asset {
    protected:
        int xPos_{};
        int yPos_{};
        std::vector<std::string> sprite_;
    public:
        Asset() = default;
        Asset(int x, int y);
        Asset(int x, int y, std::vector<std::string> sprite);

        virtual ~Asset() = default;
};

} // Asset

#endif //ASSET_H
