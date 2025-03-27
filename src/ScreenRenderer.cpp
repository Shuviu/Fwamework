//
// Created by shuviu on 3/12/25.
//
#include "../include/ScreenRenderer.h"
#include <iostream>

#include "../include/InputHandlerAsync.h"
#include "TerminalUtilities.h"

namespace Rendering {
    void ScreenRenderer::RenderFrame(const std::vector<std::vector<char>>& frame, const std::tuple<int, int>& coords) {
        // Set the cursor to init pos
        Console::SetCursor(std::get<0>(coords), std::get<1>(coords));

        // Draw frame
        for (int i = 0; i < frame.size(); i++) {

            Console::SetCursor(std::get<0>(coords) + i, std::get<1>(coords));

            for (int j = 0; j < frame[i].size(); j++) {
                std::cout << frame[i][j];
            }

            std::cout << std::endl;
        }
    }

    void ScreenRenderer::RenderFrame(const std::vector<std::vector<char>>& frame,
                                     const std::tuple<int, int>& startOldPos,
                                     const std::tuple<int, int>& endOldPos,
                                     const std::tuple<int, int>& newPos) {

        // Set Cursor to OldInit pos
        Console::SetCursor(std::get<0>(startOldPos), std::get<1>(startOldPos));

        // Reset the area
        for (int i = std::get<0>(startOldPos); i < std::get<0>(endOldPos); i++) {
            for (int j = std::get<1>(startOldPos); j < std::get<1>(endOldPos); j++) {
                std::cout << ' ';
            }

            std::cout << std::endl;
        }

        // Render new frame
        RenderFrame(frame, newPos);
    }

    void ScreenRenderer::RenderFrame(const std::vector<std::vector<char>>& frame) {
        RenderFrame(frame, {1, 0});
    }
}



