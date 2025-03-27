//
// Created by shuviu on 3/18/25.
//

#include "../include/Asset.h"

namespace Assets {
    // ---- Constructors ---- //
    Asset::Asset(int x, int y) {
        xPos_ = x;yPos_ = y;
    }
    Asset::Asset(const int x, const int y, std::vector<std::string> sprite) {
        xPos_ = x;
        yPos_ = y;
        sprite_ = std::move(sprite);
    }


} // Asset